//               __                  __
//              ( _)                ( _)
//             / / \\              / /\_\_
//            / /   \\            / / | \ \
//           / /     \\          / /  |\ \ \
//          /  /   ,  \ ,       / /   /|  \ \
//         /  /    |\_ /|      / /   / \   \_\
//        /  /  |\/ _ '_|\    / /   /   \    \\
//       |  /   |/  0 \0\ \  / |    |    \    \\
//       |    |\|      \_\_ /  /    |     \    \\
//       |  | |/    \.\ o\o)  /      \     |    \\
//       \    |     /\\`v-v  /        |    |     \\
//        | \/    /_| \\_|  /         |    | \    \\
//        | |    /__/_     /   _____  |    |  \    \\
//        \|    [__]  \_/  |_________  \   |   \    ()
//         /    [___] (    \         \  |\ |   |   //
//        |    [___]                  |\| \|   /  |/
//       /|    [____]                  \  |/\ / / ||
//      (  \   [____ /     ) _\      \  \    \| | ||
//       \  \  [_____|    / /     __/    \   / / //
//       |   \ [_____/   / /        \    |   \/ //
//       |   /  '----|   /=\____   _/    |   / //
//    __ /  /        |  /   ___/  _/\    \  | ||
//   (/-(/-\)       /   \  (/\/\)/  |    /  | /
//                 (/\/\)           /   /   //
//                        _________/   /    /
//                       \____________/    (
#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define rep1(i,n) for(int i=1;i<(int)n;i++)

/******good luck******/
const int maxn = 1e5+5;
int32_t main(){
    IOS;
    int n,ans=0,a,b,f;
    cin>>n>>f;
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    b=f;
    rep1(i,n){
        cin>>a;
        if(b>a){
            if(ans){
                cout<<-1<<endl;
                return 0;
            }
            ans=i;
        }
        b=a;
    }
    if(a>f && ans)
        cout<<-1<<endl;
    else if(ans==0)
        cout<<ans<<endl;/* FUCK STUPID TYPO */
    else
        cout<<n-ans<<endl;
    return 0;
}