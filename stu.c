// WinPcap_TCP_DumpDlg.cpp: 實作檔案
//

#include "stdafx.h"
#include "WinPcap_TCP_Dump.h"
#include "WinPcap_TCP_DumpDlg.h"
#include "afxdialogex.h"
#include "map"
#include "utility"
#include "iostream"
#include "string"
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define mk make_pair

// 對 App About 使用 CAboutDlg 對話方塊

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

// 程式碼實作
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CWinPcapTCPDumpDlg 對話方塊



CWinPcapTCPDumpDlg::CWinPcapTCPDumpDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_WINPCAP_TCP_DUMP_DIALOG, pParent)
	, m_Edit1(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWinPcapTCPDumpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Edit1);
	DDX_Control(pDX, IDC_EDIT1, m_Edit11);
}

BEGIN_MESSAGE_MAP(CWinPcapTCPDumpDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CWinPcapTCPDumpDlg::OnBnClickedButton1)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CWinPcapTCPDumpDlg 訊息處理常式

BOOL CWinPcapTCPDumpDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 將 [關於...] 功能表加入系統功能表。

	// IDM_ABOUTBOX 必須在系統命令範圍之中。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 設定此對話方塊的圖示。當應用程式的主視窗不是對話方塊時，
	// 框架會自動從事此作業
	SetIcon(m_hIcon, TRUE);			// 設定大圖示
	SetIcon(m_hIcon, FALSE);		// 設定小圖示

	// TODO: 在此加入額外的初始設定

	return TRUE;  // 傳回 TRUE，除非您對控制項設定焦點
}

void CWinPcapTCPDumpDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果將最小化按鈕加入您的對話方塊，您需要下列的程式碼，
// 以便繪製圖示。對於使用文件/檢視模式的 MFC 應用程式，
// 框架會自動完成此作業。

void CWinPcapTCPDumpDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 繪製的裝置內容

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 將圖示置中於用戶端矩形
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 描繪圖示
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 當使用者拖曳最小化視窗時，
// 系統呼叫這個功能取得游標顯示。
HCURSOR CWinPcapTCPDumpDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// ###############################################
// ############## 程式宣告、定義、... ############
#define HAVE_REMOTE
#pragma comment(lib,"WinPcap/lib/wpcap.lib")
#include "WinPcap/include/pcap.h"

// 全域變數: pcap_open() 與 pcap_next_ex() 都會用到
// pcap_open() 開啟網路裝置準備側錄封包
// pcap_next_ex() 側錄封包
pcap_t *fp; 

// 網路四層封包 Header 結構
// MAC(14)+IP(20)+ TCP(20) + Application Data(..)
// ..............+ UDP(😎  + Application Data(..)
struct MAC // MAC[14]
{	unsigned char  DMAC[6];
	unsigned char  SMAC[6];
	unsigned char  Type[2];
};
struct IP // IP(20)
{	unsigned char  Ver[2], Len[2];
	unsigned char  ID[2], Frag[2];
	unsigned char  Time, Protocol, Check[2];
	unsigned char  SIP[4], DIP[4];
};
struct TCP // TCP(20)
{	unsigned char  SPort[2], DPort[2];
	unsigned char  Seq[4], Ack[4];
	unsigned char  Offset, Flag11, Window[2];
	unsigned char  Check[2], Urgent[2];
};
struct UDP // UDP(😎
{	unsigned char  SPort[2], DPort[2];
	unsigned char  Len[2], Check[2];
};

// 開啟網路卡側錄封包Driver(WinPcap Driver)
void CWinPcapTCPDumpDlg::OnBnClickedButton1()
{   // 1.變數宣告
	pcap_if_t          *alldevs, *d;
	int                res, Len,inum, i,n;
	char               S1[2000],errbuf[PCAP_ERRBUF_SIZE];
	struct pcap_pkthdr *header;
	unsigned char      *pkt_data;
	wchar_t            SS1[2000];

	// 2.搜尋與顯示網路卡
	UpdateData(1); m_Edit1 += L"網路卡列表\r\n"; UpdateData(0);
	pcap_findalldevs_ex("rpcap://", NULL, &alldevs, errbuf);
	d = alldevs;  n = 0;
	while (d != 0)
	{   sprintf_s(S1,2000, "n=%d Name=%s  Description=%s\r\n",n++, d->name, d->description);
	    for (i = 0; i <=strlen(S1); i++) SS1[i] = (wchar_t)S1[i];
		UpdateData(1); m_Edit1 += SS1; UpdateData(0);
	    d = d->next;	
	}

	// 3.選擇網路卡 & 開啟網卡
	inum = 0; // 選擇網路卡編號(0~5)，每人電腦均不同，請一個個編號試試看，直到有攔到封包為止
	for (d = alldevs, i = 0; i < inum - 1; d = d->next, i++);
	fp = pcap_open(d->name, 100, 1,	20,	NULL, errbuf);

	// 4.啟動計時器 抓取封包
	SetTimer(123, 1, 0); // 每隔100ms抓一次，有點慢，最好用 Thread Function,才不會漏掉
	UpdateData(1); m_Edit1 += L"開始抓封包\r\n"; UpdateData(0);
}


// 定時(每隔100ms，有點慢)抓取封包
void CWinPcapTCPDumpDlg::OnTimer(UINT_PTR nIDEvent)
{
	char               S1[2000],S2[100];
	wchar_t            SS1[2000];
	int                j,res, Len, App_Len;
	struct pcap_pkthdr *header;
	const u_char       *pkt_data;
	MAC  *lpMAC;
	IP   *lpIP;
	TCP  *lpTCP;
	UDP  *lpUDP;
	unsigned char *lpApp;

    if (nIDEvent == 123)
	{
		// 定時(每隔100ms，有點慢)抓取封包
		if ((res = pcap_next_ex(fp, &header, &pkt_data)) >= 0)
		{
			// 1.過濾 TCP 封包: MAC(14)+IP(20)+TCP(20): 
			if ((header->caplen > 54) &&           // TCP封包至少54 Bytes
				(pkt_data != (u_char*)0xcccccccc))// 避免因 pkt_data指標 ==0xcccc...而當機
			{
				lpMAC = (MAC*)&pkt_data[0];
				lpIP = (IP*)&pkt_data[14];
				lpTCP = (TCP*)&pkt_data[34];
				lpApp = (unsigned char*)&pkt_data[54];	App_Len = header->caplen - 54;
				if (lpIP->Protocol == 0x06) // TCP=0x06, UDP=0x11
				{
					
					map<int, pair<string, string>  > mp;
					mp[69] = mk("USA", "FaceBook");
					mp[13] = mk("Hong Kong", "Microsoft Azure");
					mp[40] = mk("United States", "Microsoft Azure");
					mp[35] = mk("Japan", "Google Cloud");
					mp[13] = mk("Singapore", "Amazon.com");
					mp[104] = mk("United States", "Cloudflare");
					mp[192] = mk("United States", "Google Cloud");
					mp[18] = mk(" Japan", "Amazon.com");
					mp[103] = mk("India", "unknown");


					// 1.1.製造 TCP 封包參數
					sprintf_s(S1, "TCP SPort=%d DPort=%d SIP=%d.%d.%d.%d DIP=%d.%d.%d.%d \nmaybe Ur visiting %s %s \nData(%d)=",
						(int)(lpTCP->SPort[1]) + ((int)lpTCP->SPort[0] << 😎,
						(int)(lpTCP->DPort[1]) + ((int)lpTCP->DPort[0] << 😎,
						lpIP->SIP[0], lpIP->SIP[1], lpIP->SIP[2], lpIP->SIP[3],
						lpIP->DIP[0], lpIP->DIP[1], lpIP->DIP[2], lpIP->DIP[3],
						mp[(int)lpIP->DIP[0]].first.c_str(),
						mp[(int)lpIP->DIP[0]].second.c_str(),
						App_Len);

					// 1.2.列印 10 Bytes 以內Data
					j = App_Len; if (j > 10) j = 20;
					for (int i = 0; i < j; i++)
					{
						if ((lpApp[i] >= 0x20) && (lpApp[i] <= 0x7F)) // 只列印英文+數字+符號
						{
							S2[0] = lpApp[i]; S2[1] = 0;  strcat_s(S1, 2000, S2);
						}
					}
					strcat_s(S1, 2000, "...\r\n"); // 跳行
					for (int i = 0; i <= strlen(S1); i++) SS1[i] = (wchar_t)S1[i];// 1Byte to 2Bytes轉換
												// 1.3.顯示
					UpdateData(1); m_Edit1 += SS1; UpdateData(0);
					m_Edit11.LineScroll(m_Edit11.GetLineCount()); // 自動捲動到最後一行
				}
			}
		}
	}
	CDialogEx::OnTimer(nIDEvent);
}