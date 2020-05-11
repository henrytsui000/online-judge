// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// #define IOS ios_base::sync_with_stdio(0); cin.tie(0)
// #define endl '\n'
// #define all(a) a.begin(),a.end()
// #define sz(a) ((int)a.size())
// #define rep(i,n) for(int i=0;i<(int)n;i++)
// #define eb emplace_back
// const int maxn = 1e5+5;

// /*
// struct 這個資料結構的名稱{
//     裡面要包含的元素型態 元素名稱;
// };
// 這個資料結構的名稱 你要怎麼開;

// 下面的範例是我的資料結構叫panpan 裡面存string double int各一個
// 就像是int 裡面存可以存一個整數

// 然後我開一個panpan的結構 名稱叫做mine
// 就像是會int x;一個int 的結構 叫做x

// 資料結構名稱.裡面存的名字 就可以叫出他來用
// 像是mine.name 指的是形狀是panpan的結構中 名為mine結構 裡面存string的東西 叫做name
// 有點像是pair<int,int> p; p.first的感覺
// */

// struct panpan{
//     string name;
//     double thickness;
//     int time;
// };

// panpan mine;
// panpan pencil_box[10];

// int main(){
//     panpan red;
//     cin>>mine.name>>mine.thickness>>mine.time;
//     cout<<mine.name<<endl;
//     rep(i,10)
//         cin>>pencil_box[i].time;
//     cout<<mine.time+pencil_box[2].time<<endl;
//     return 0;
// }



#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
int main(){
    int sma=10001;
    int lar=0;
    int num,a;
    cin >> num;
    cout<<"helllo world"<<endl;
    rep(i,num){
        cin>>a;
        if(a>=lar)
            a=lar;
        if(a<=sma)
            a=sma;
    }
    cout << lar << " "<<  sma<< endl;
}
