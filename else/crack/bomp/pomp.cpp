#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<ld,ld>;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define all(a) a.begin(),a.end()
#define sz(a) ((int)a.size())
#define F first
#define S second
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<(int)n;i++)
#define pb push_back
#define p(x) (toupper(x)-'@')
#define nbdy(x,y) (i!=4&&(x+dir[i].F!=0)&&(x+dir[i].F!=maxn+1)&&(y+dir[i].S!=0)&&(y+dir[i].S!=maxn-1))
#define eb emplace_back
#define mp(a,b) make_pair(a,b)
#define cans cout<<ans<<endl
#define in cout<<"in lar"<<endl
#define sort_uni(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define get(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
template<typename T1,typename T2>
ostream& operator<<(ostream& out,pair<T1,T2> P){
    out<<'('<<P.F<<','<<P.S<<')';
    return out;
}

//}}}
const ll INF64=8000000000000000000LL;
const int INF=0x3f3f3f3f;
const ll MOD=ll(1e9+7);
const ld PI=acos(-1);
const ld eps=1e-9;
//const ll p=880301;
//const ll P=31;

ll mypow(ll a,ll b){
    ll res=1LL;
    while(b){
        if(b&1) res=res*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return res;
}

/******good luck******/
const int maxxn = 80;
int maxn,bomb,flag_cnt,t_move;
bool die=false;
char arr[maxxn][maxxn];
char ans[maxxn][maxxn];
clock_t t_start;
pii dir[9];

void init(){
    cout<<"give the size and num of bomb"<<endl;
    cin>>maxn>>bomb;
    maxn += 2;
    srand(time(NULL));
    rep(i,9) dir[i].F=(i%3)-1,dir[i].S=(i/3)-1;
    memset(arr,'$',sizeof(arr));
    arr[maxn-1][maxn-1]='@';
    rep(i,maxn-1)
        arr[i][0]=arr[0][i]=arr[i][maxn-1]=arr[maxn-1][i]='A'+i-1;
}

int count_bomb(int x,int y){
    int cnt=0;
    rep(i,9)
        if(nbdy(x,y)&&ans[x+dir[i].F][y+dir[i].S]=='X')
            cnt++;
    return cnt;
}

void give_map(){
    int cnt = bomb;
    rep(i,maxn-1)
        ans[i][0]=ans[0][i]=ans[i][maxn-1]=ans[maxn-1][i]='A'+i-1;
    ans[0][0]=ans[0][maxn-1]=ans[maxn-1][0]=ans[maxn-1][maxn-1]='@';

    while(cnt){
        int x=rand()%(maxn-2)+1,y=rand()%(maxn-2)+1;
        if(!ans[x][y])
            ans[x][y]='X',cnt--;
    }

    rep1(i,maxn-1)
        rep1(j,maxn-1)
            if(!ans[i][j])
                ans[i][j]='0'+count_bomb(i,j);
    ofstream fout("pomp.txt");
    rep(i,maxn){ 
        rep(j,maxn)
            fout<<ans[i][j]<< ' ';
        fout<<endl;
    }
}

void check_time(){
    double duration;
    duration = ( clock() - t_start ) / (double) CLOCKS_PER_SEC;
    cout<<"now time:"<<duration*10000<<endl;
}

void help(){
    cout<<"use flag x y to flag a point"<<endl
        <<"use unflag x y to unflag a point"<<endl
        <<"use unknow x y mark a point uncertain"<<endl
        <<"use step x y to step a point"<<endl
        <<"use detail to see more detail"<<endl
        <<"use show to see the map right now"<<endl;
}

int open_counter(int t){
    if(t==1){
        int ret = 0;
        rep1(i,maxn-1) rep1(j,maxn-1)
            if(arr[i][j]!='$'&&arr[i][j]!='F')
                    ret++;
        return ret;
    }else if(t==2){
        int ret = 0;
        rep1(i,maxn-1) rep1(j,maxn-1)
            if(arr[i][j]=='F')
                    ret++;
        return ret;

    }
}

bool count_flag(int x,int y){
    int ret=0;
    rep(i,9) if(i!=4) 
        if(arr[x+dir[i].F][y+dir[i].S]=='F')
            ret++;
    if(arr[x][y]-ret=='0')
        return true;
    else return false;
}

void step(int x,int y){
    if(x*y==0||x==maxn-1||y==maxn-1||arr[x][y]=='F')
        return ;
    if(ans[x][y]=='X'&&(die=1)) return ;
    else if(ans[x][y]=='0'&&arr[x][y]=='$'){
        arr[x][y]=ans[x][y];
        rep(i,9) if(nbdy(x,y)) 
            step(x+dir[i].F,y+dir[i].S);
    }else if(arr[x][y]=='$') arr[x][y]=ans[x][y];
}

void extra_step(int x,int y){
    rep(i,9) if(nbdy(x,y)){
        if(arr[x+dir[i].F][y+dir[i].S]!='F'){
            if(ans[x+dir[i].F][y+dir[i].S]=='X'&&(die=1)) return ;
            arr[x+dir[i].F][y+dir[i].S]=ans[x+dir[i].F][y+dir[i].S];
        }
    }
}

void show_detail(){
    cout<<"total bomb: "<<bomb<<endl;
    cout<<"total flag: "<<open_counter(2)<<endl;
    cout<<"remaining bombs: "<<bomb-open_counter(2)<<endl;
    cout<<"opening space: "<<open_counter(1)<<endl;
    cout<<"total move: "<<t_move<<endl;
}

void start(){
    char x,y;
    t_start=time(NULL);
    cout<<"the game have been start"<<endl
        <<"u can type help for help"<<endl;
    string str;
    cout<<">>>";
    while(cin>>str){
        if(str=="flag"||str=="f"){
            cin>>x>>y;
            arr[p(x)][p(y)]='F';
        }else if(str=="step"||str=="s"){
            cin>>x>>y;
            while(!t_move&&ans[p(x)][p(y)]=='X'){
                give_map();
            }
            t_move++;
            if(arr[p(x)][p(y)]=='F')
                cout<<"you can't step flag point"<<endl;
            else if(arr[p(x)][p(y)]<'9'&&arr[p(x)][p(y)]>='0'&&count_flag(p(x),p(y))){
                extra_step(p(x),p(y));
            }else step(p(x),p(y));
        }else if(str=="unknow"||str=="?"){
            cin>>x>>y;
            arr[p(x)][p(y)]='?';
        }else if(str=="unflag"||str=="uf"){
            cin>>x>>y;
            arr[p(x)][p(y)]='$';
        }else if(str=="show"||str=="d"){
            rep(i,maxn){
                rep(j,maxn)
                    if(arr[i][j]=='0') cout<<"  ";
                    else cout<<arr[i][j]<<' ';
                cout<<endl;
            }
        }else if(str=="detail"||str=="t"){
            cout<<"time: "<<(time(NULL)-t_start)/60<<"min "
                <<(time(NULL)-t_start)%60<<"sec"<<endl;
            show_detail();
        }else if(str=="help"||str=="h"){
            help();
        }else if(str=="ans"||str=="a"){
            rep(i,maxn){
                rep(j,maxn)
                    if(ans[i][j]=='0') cout<<"  ";
                    else  cout<<ans[i][j]<<' ';
                cout<<endl;
            }
        }else if(str=="muti-step"||str=="ms"){
            while(cin>>x>>y){
                if(x=='-'&&y=='-')
                    break;
                t_move++;
                if(arr[p(x)][p(y)]=='F')
                    cout<<"you can't step flag point"<<endl;
                else if(arr[p(x)][p(y)]<'9'&&arr[p(x)][p(y)]>='0'&&count_flag(p(x),p(y))){
                    extra_step(p(x),p(y));
                }else step(p(x),p(y));
            }
        }else if(str=="muti-flag"||str=="mf"){
            while(cin>>x>>y){
                if(x=='-'&&y=='-')
                    break;
                arr[p(x)][p(y)]='F';
            }
        }else{
            cout<<"unknown choice"<<endl;
        }
        if(die) break;
        else if((maxn-2)*(maxn-2)==bomb+open_counter(1)) break;
        cout<<">>>";
    }
    if(die){
        cout<<"u fucking die"<<endl;
        rep(i,maxn){
            rep(j,maxn)
                if(ans[i][j]=='0') cout<<"  ";
                else  cout<<ans[i][j]<<' ';
            cout<<endl;
        }
    }else{
        cout<<"u win!"<<endl;
    }
}

int32_t main(){
    init();
    give_map();
    start();
    return 0;
}