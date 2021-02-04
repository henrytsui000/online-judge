#include <bits/stdc++.h>//include <iostream>, <string>, <vector>等等
#include <conio.h>//遊戲相關
#include <windows.h>//遊戲相關
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)// 節省for迴圈的打字量
#define F first   //pair's first element 
#define S second  //pair's second element
using pii = pair<int, int>;//pair 就像一個 array 有兩個element(a.frist,a.second)
using piit = pair<pair<int, int>, time_t>;//pitt 裡面為一個pair還有一個long( time_t is long) 
#define sz(a) ((int)a.size())//節省打.size()的時間

vector<int> b_dx, b_dy;  //bomb 的爆炸範圍
//ex: dx[0], dy[0]為getch()為w時，x座標+=dx[0];y座標+=dy[0]
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
//mp使char對應到int(輸入wasdf okl;j用);prt使int對應到string(印地圖時用)
map<char, int> mp;
map<int, string> prt;

int bomb_range;//設定bomb range 的參數(十字多長)
int site[2][2];   //ex: site[0][0]is P1 xcoordinate
int arr[12][24];  //the map
vector<piit> bomb[2];//ex: P1 first bomb -> bomb[0][0].F.F bomb[0][0].F.S bomb[0][0].S (x,y,time)

//刷新
void new_screen(int xpos, int ypos) {
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = xpos;
    scrn.Y = ypos;
    SetConsoleCursorPosition(hOuput, scrn);
}
//顯示規則
void show_rule() {
    cout << "Player1->up:w, right:a, down:s, left:d\n";
    cout << "Player2->up:o, right:k, down:l, left:;\n";
}
//清游標，define mp, prt
void init() {
    //ex: w,o的個位數一樣動作也一樣(之後act比較好處理)
    mp['w'] = 0, mp['a'] = 1, mp['s'] = 2, mp['d'] = 3, mp['f'] = 4;
    mp['o'] = 10, mp['k'] = 11, mp['l'] = 12, mp[';'] = 13, mp['j'] = 14;
    //防誤觸
    mp['q'] = -3, mp['z'] = -3, mp['x'] = -3, mp['c'] = -3, mp['r'] = -3, mp['e'] = -3, mp['v'] = -3;
    mp['i'] = -3, mp['m'] = -3, mp[','] = -3, mp['.'] = -3, mp['\''] = -3, mp['p'] = -3, mp['9'] = -3;
    //印地圖對應用
    prt[-1] = "--", prt[0] = "  ", prt[1] = "[]", prt[2] = "P1", prt[3] = "P2";
    prt[4] = "1@", prt[5] = "2@", prt[6] = "XX", prt[7] = "%%";
    //消游標
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle, &CursorInfo);
    CursorInfo.bVisible = false;
    SetConsoleCursorInfo(handle, &CursorInfo);
}
//開地圖檔案，印在array裡
void build_map() {
    string option, graph = "graph", txt = ".txt";
    cout << "Which map you want to choose(0,1,2,3)?";
    cin >> option;
    ifstream fin(graph + option + txt);
    rep(i, 12) rep(j, 24)
        fin >> arr[i][j];
}
//設定爆炸強度(十字範圍)
void set_bomb() {
    cout << "Decide bomb range? ";
    cin >> bomb_range;
    for (int i = -bomb_range; i <= bomb_range; i++)
        for (int j = -bomb_range; j <= bomb_range; j++)
            if (i*j == 0)
                b_dx.push_back(i), b_dy.push_back(j);//if bombrange =3 ->(-3,0), (-2,0),(-1,0),(0,-3),(0,-2)....(3,0)
}
//設定兩個人的位置，call show_rule(),build_map(),set_bomb()
void rst() {
    site[0][0] = 5, site[0][1] = 5;
    site[1][0] = 5, site[1][1] = 19;
    show_rule();
    build_map();
    set_bomb();
}
//確認座標合不合法
bool legal(pii plc, int x) {//plc為座標
    if (plc.F + b_dx[x] < 0 || plc.F + b_dx[x] > 12) return false;//確認x值有沒有出界
    if (plc.S + b_dy[x] < 0 || plc.S + b_dy[x] > 24) return false;//確認y值有沒有出界
    if (arr[plc.F + b_dx[x]][plc.S + b_dy[x]] == -1) return false;//看有沒有在牆上
    return true;
}
//印爆炸(%%)(確認合法性後印7)
void show_bomb(pii plc) {
    for (int i = 0; i < sz(b_dx); i++)
        if (legal(plc, i))//確認合法性
            arr[plc.F + b_dx[i]][plc.S + b_dy[i]] = 7;//確認合法性後印7
}
//處理地圖 (用show_bomb),吃tmp
void show_map(int flag) {
    new_screen(0, 4);//清第四行以下
    rep(i, 2) 
        for (int j = sz(bomb[i]) - 1; j >= 0; j--) 
            if (time(NULL) - bomb[i][j].S > 3)
                show_bomb(bomb[i][j].F);//deta time>3, show_bomb(bomb(x,y)), which means the place nearby bomb = 7;
            else 
                arr[bomb[i][j].F.F][bomb[i][j].F.S] = 4 + i;//<3, P1bomb= 4, P2bomb=5
    rep(i, 2) 
        arr[site[i][0]][site[i][1]] = 2 + i;//P1 = 2, P2 = 3

    if (flag)//if (flag==1||flag===2)  引數由check_die來，flag為true means 人死
        arr[site[flag - 1][0]][site[flag - 1][1]] = 6;//6 -> XX

    rep(i, 12) rep(j, 24)
        cout << prt[arr[i][j]] << " \n"[j == 23];  //str[0]=' ',str[1]='\n'
    // rep(i, 12) { 
    //     rep(j, 24)
    //         cout << prt[arr[i][j]] << ' ';
    //     cout << '\n';
    // }
    rep(i, 12) rep(j, 24) 
        if (arr[i][j] > 1)//清空-1 0 1以外的東西 即讓人不會印兩次，箱子不會再印
            arr[i][j] = 0;
}
//0 1(P1 died) 2(P2 died) 用爆炸範圍去
int check_die() {
    rep(i, 2) for (piit x : bomb[i]) {//check bomb exlposure 有沒有炸到人 (rep為做P1,P2)
        if (time(0) - x.S > 3) {//element time>3
            rep(j, 2) //bombrange + -> 加abs
                if (abs(x.F.F - site[j][0]) + abs(x.F.S - site[j][1]) <= bomb_range && !(abs(x.F.F - site[j][0]) * abs(x.F.S - site[j][1]))) 
                    return j + 1;//abs(x.F.F - site[j][0])<=bomb_range&&abs(x.F.S - site[j][1]<=bomb_range && !(abs(x.F.F - site[j][0]) * abs(x.F.S - site[j][1]))
        }
    }
    return 0;
}
//遊戲開始(用check_die, show_map)
void start() {
    char key;
    while (true) {
        if (kbhit()) {//吃指令
            key = getch();
            int act = mp[key] % 10, usr = mp[key] / 10;//ex: w,o的值%10都為0; w,o/10為0代表P1(1代表P2)
            if (act <4 &&act>=0) {//下一步為零 &&不為另一個人usr 剛好為0or1(use !)
                if (arr[site[usr][0] + dx[act]][site[usr][1] + dy[act]] == 0 && !(site[usr][0] + dx[act] == site[!usr][0] && site[usr][1] + dy[act] == site[!usr][1])) {
                    site[usr][0] += dx[act], site[usr][1] += dy[act];
                }
            }
            if (act == 4) {//放炸彈
                bomb[usr].push_back(make_pair(make_pair(site[usr][0], site[usr][1]), time(NULL)));
            }
        }
        rep(i, 2) while (sz(bomb[i])) {//size ==0不會進去
            if (time(0) - bomb[i][0].S > 6) { //check 那人的第0項是因為erase會把原本的第一項變成第零項，以此類推
                bomb[i].erase(bomb[i].begin());//刪過期炸彈(>6s) 
            }
            else 
                break;
        }
        int tmp = check_die();//tmp 為show_map的flag
        show_map(tmp);
        if (tmp) {//if(tmp==1||tmp==2)
            cout << "Player " << 1 + (tmp) % 2 << " win!" << endl;//tmp = 1, P1死，P2贏
            return;
        }
    }
}
//放在gogo的while裡面
bool restart() {
    string key;
    while (true) {//只吃n, y
        cout << "new game? y/n : ";
        cin >> key;
        if (key == "y") 
            return true;
        else if (key == "n") 
            return false;
    }
}
//讓main少一點 
void gogo() {
    init();  //初始化界面
    do {
        system("cls");    //清空頁面
        rst();            //選擇地圖/爆炸半徑
        start();          //遊戲開始
    } while (restart());  //選擇是否要重新開始
}
//*******************************************
int main() {
    gogo();  //執行程式
    return 0;
}