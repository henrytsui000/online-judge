#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define all(a) a.begin(),a.end()
#define sz(a) ((int)a.size())
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define eb emplace_back
using pii = pair<int,int>;
#define F first
#define S second
#define mem(a,b) memset(a,0,sizeof(a));
#define chg(arr,a) rep(i,4)arr[i]=a%10,a/=10;
const int maxn = 10005;
const int maxm=1e4;
vector<int> pos;

bool num[maxn];
bool can[maxn];
int maxt=0;

void init(){
    mem(num,0);
    // maxt=0;
    mem(can,0);
    rep(i,5) rep(j,5)
        if(i+j<=4&&(i*10+j!=31))
            pos.eb(i*10+j);
    rep(k,maxm){
        int arr[4],kt=k;
        chg(arr,kt);
        bool key = true;
        rep(i,4) rep(j,4)
            if(i!=j&&arr[i]==arr[j])
                key = false;
        if(key)
            num[k]=can[k]=true;
    }
}

int checker(int a,int b){
    int arr[4],brr[4],ret=0;
    chg(arr,a);
    chg(brr,b);
    rep(i,4) rep(j,4)
        if(i!=j) ret+=(arr[i]==brr[j]);
        else if(arr[i]==brr[i]) ret+=10;
    return ret;
}

int cut(int n,int A,bool u){
    int ret=0;
    rep(i,maxm){
        if(num[i]&&checker(i,n)==A){
            ret++;
        }else if(num[i]&&u)
            num[i]=0;
    }
    return ret;
}

void guess(){
    int A,B,G=2780,T=0;
    while(true){
        T++;
        cout<<"GUESS: ";
        if(G<1000)
            cout<<0;
        cout<<G<<endl<<"A? B?"<<endl;
        string str;
        cin>>str;
        A=(str[0]-'0')*10+(str[1]-'0');
        if(A==40){
            cout<<"END: "<<T<<endl;
            return ;
        }
        int cnt=cut(G,A,1),arr[5][5];
        // if(cnt==0){
        //     cout<<"IMPOSSEILBE"<<endl;
        //     return ;
        // }
        cout<<"last:"<<cnt<<endl;
        // rep(k,maxm)
            // if(num[k])
                // cout<<k<<' ';
            // cout<<endl;
        pii grt;
        grt.S=maxm;
        rep(k,maxm) if(num[k]){
            memset(arr,0,sizeof(arr));
            int ma=0;
            for(int j:pos){
                arr[j/10][j%10]=cut(k,j,0);
                // cout<<j<<":";
                // cout<<arr[j/10][j%10]<<' ';
                ma=max(arr[j/10][j%10],ma);
            }
            // cout<<endl;
            if(ma<grt.S)
                grt.F=k,grt.S=ma;
        }
        G=grt.F;
        cout<<"MA:"<<grt.S<<endl;
    }
}


void goon(){
    int GU=0;
    while(!can[GU]) GU=rand()%10000;
    cout<<"ANS:"<<GU<<" ,";
    int A,B,G=2780,T=0;
    while(true){
        T++;
        // cout<<"GUESS: ";
        // if(G<1000)
        //     cout<<0;
        // cout<<G<<endl<<"A? B?"<<endl;
        A=checker(GU,G);
        // cout<<A/10<<' '<<A%10<<endl;
        if(A==40){
            cout<<"END: "<<T<<endl;
            maxt=max(maxt,T);
            init();
            return ;
        }
        int cnt=cut(G,A,1),arr[5][5];
        // cout<<cnt<<' ';
        pii grt;
        grt.S=maxm;
        rep(k,maxm) if(num[k]){
            memset(arr,0,sizeof(arr));
            int ma=0;
            for(int j:pos){
                arr[j/10][j%10]=cut(k,j,0);
                ma=max(arr[j/10][j%10],ma);
            }
            if(ma<grt.S)
                grt.F=k,grt.S=ma;
        }
        G=grt.F;
    }

}

int32_t main(){
    srand(time(NULL));
    init();
    cout<<"Fin init"<<endl;

    int n;cin>>n;
    rep(i,n) {
        cout<<"T:"<<i+1<<' ';
        goon();
    }
    cout<<"MAX TRY"<<maxt<<endl;

    // guess();
    
    return 0;
}

/*
00 88 360
01 378 1440
02 304 1260
03 264 75
10 480 126
11 720 180
12 216 80
13 8 4
20 180 48
21 72 30
22 6 4
*/