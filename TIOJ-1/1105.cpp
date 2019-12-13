#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
const int maxn = 3005;
using pii=pair<int,int>;
#define F first 
#define S second
#define mp(a,b) make_pair(a,b)
#define pb push_back 
#define all(a) a.begin(),a.end()
#define pp pop_back
#define sz(a) ((int)a.size())
template<typename T1,typename T2>
ostream& operator<<(ostream& out,pair<T1,T2> P){
    out<<P.F<<' '<<P.S;
    return out;
}
double dis(pii a,pii b){
    int x=abs(a.F-b.F);
    x*=x;
    int y=abs(a.S-b.S);
    y*=y;
    return sqrt(x+y);
}

vector<pair<pii,int>> vec;
vector<pair<pii,int>> con;
int n;

int cross(pii a,pii b,pii c){
    int x1=a.F-c.F;
    int y1=a.S-c.S;
    int x2=b.F-c.F;
    int y2=b.S-c.S; 
    return x1*y2-x2*y1;
}

void convex(){
    sort(all(vec));
    int u=0,d=0;
    rep(i,n){
        while(u>=2&&cross(con[u-2].F,con[u-1].F,vec[i].F) > 0){
            con.pp();
            u--;
        }
        u++;
        con.pb(vec[i]);
    }
    con.pp();
    for(int i=n-1;i>=0;i--){
        while(d>=2&&cross(con[d+u-3].F,con[d+u-2].F,vec[i].F) > 0){
            con.pp();
            d--;
        }
        d++;
        con.pb(vec[i]);
    }
    con.pp();
}

int main(){
    IOS;
    while(cin>>n&&n){
        int a,b;
        rep(i,n){
            cin>>a>>b;
            vec.pb(mp(mp(a,b),i));
        }
        convex();
        int s=sz(con);
        int ans1=con[0].S,ans2=con[1].S;
        double now=dis(con[0].F,con[1].F);
        rep(i,s){
            rep(j,s){
                double k=dis(con[i].F,con[j].F);
                if(k>now){
                    now=k,ans1=con[i].S,ans2=con[j].S;
                }else if(k==now){
                    if(con[i].S<ans1){
                        ans1=con[i].S;
                        ans2=con[j].S;
                    }else if(con[i].S==ans1){
                        ans2=min(ans2,con[j].S);
                    }
                }
            }
        }
        cout<<ans1<<' '<<ans2<<endl;
        vec.clear();
        con.clear();
    }
    return 0;
}
/*
15
2 0
1 1
1 -1
0 0
-2 -2

-2 -1
-4 -1
-4 0
0 4
2 3

-1 3
-2 2
-3 3
-4 2
-5 0
*/