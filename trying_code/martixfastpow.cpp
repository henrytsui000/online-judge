#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)

struct mat{
    int arr[2][2];

};

mat muti(mat a,mat b){
    mat ret;
    rep(i,2) rep(j,2)
        ret.arr[i][j]=0;//歸零
    rep(i,2) rep(j,2) rep(k,2)//矩陣乘法
        ret.arr[j][i]+=a.arr[k][i]*b.arr[j][k];
    return ret;
}

mat ans;
void mypow(mat a,int b){
    while(b){
        if(b&1)
            ans=muti(ans,a);//ans×a
        a=muti(a,a);//a×a
        b>>=1;
    }
    cout<<ans.arr[0][0]<<endl;
}

int main(){
    mat a;int n;
    ans.arr[0][0]=ans.arr[1][0]=1;
    a.arr[0][1]=1,a.arr[1][1]=0;
    cin>>a.arr[0][0]>>a.arr[1][0]>>n;
    mypow(a,n);
    return 0;
}