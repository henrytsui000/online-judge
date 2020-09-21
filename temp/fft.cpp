#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<((int)n);i++)
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define sz(n) ((int)n.size())
using namespace std;

const int N=2000010;
const double pi=acos(-1.0);
struct node{
    double x,y;
    node (double xx=0,double yy=0){
        x=xx;y=yy;
    }
};
node a[N],b[N],omega[N],a_omega[N];
int n,m,fn,num[N];

node operator +(const node &a,const node &b){return node (a.x+b.x,a.y+b.y);}
node operator -(const node &a,const node &b){return node (a.x-b.x,a.y-b.y);}
node operator *(const node &a,const node &b){return node (a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);}

void init(int n){
    rep(i,n){
        omega[i]=node(cos(2.0*pi*i/n),sin(2.0*pi*i/n));
        a_omega[i]=node(cos(2.0*pi*i/n),-sin(2.0*pi*i/n));
    }
}

void FFT(int n,node *a,node *w){
    int i,j=0,k;
    rep(i,n){
        if (i>j) swap(a[i],a[j]);
        for (int l=n>>1;(j^=l)<l;l>>=1);
    }
    for (i=2;i<=n;i<<=1){
        int m=i>>1;
        for (j=0;j<n;j+=i)
            rep(k,m){
                node z=a[j+k+m]*w[n/i*k];
                a[j+k+m]=a[j+k]-z;
                a[j+k]=a[j+k]+z;
            }
    }
}

void check_omega(){
	cout<<"---line---"<<endl;
	cout<<"omega"<<endl;
	rep(i,fn){
	   	if(omega[i].x<0.00001&&omega[i].x>-0.00001)
	   		cout<<0<<' ';
	    else cout<<omega[i].x<<' ';
		if(omega[i].y<0.00001&&omega[i].y>-0.00001)
			cout<<0<<endl;
		else cout<<omega[i].y<<endl; 
	}
	cout<<"END_omega"<<endl;
	cout<<"---line---"<<endl;
}

int main(){
	string c1,c2;
	cin>>c1>>c2;
    n=c1.size()-1;
    rep(i,sz(c1)) a[n-i].x=(double)(c1[i]-'0'); 
    m=c2.size()-1;
    rep(i,sz(c2)) b[m-i].x=(double)(c2[i]-'0');    
    fn=1;
    while(fn<=m+n)	
        fn<<=1;
        
    init(fn);
    
    check_omega();

    //頻域->時域 
    FFT(fn,a,omega);
    FFT(fn,b,omega);
    
    //時域->時域 
    rep(i,fn+1)
        a[i]=a[i]*b[i];
            
    //時域->頻域 
    FFT(fn,a,a_omega);
    rep(i,fn+1)
        num[i]=(int)(a[i].x/fn+0.5);
            
    //進位 
    rep(i,fn+1){
        num[i+1]+=num[i]/10;
        num[i]%=10;
    }
    
    //輸出 
    int len=m+n+1;
    while (num[len]==0)
        len--;
    for(int i=len;i>=0;i--)
        cout<<num[i];
    cout<<endl;
    return 0;
}
/*
123 * 45

fn = 4

04000
01300
00220
00015
-----
05535

*/
