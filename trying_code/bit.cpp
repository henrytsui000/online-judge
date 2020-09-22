#include<bits/stdc++.h>

using namespace std;

vector<int> vec;
int main(){
    int a;
    cin>>a;
    printf("%b\n",a)
    while(a){
        vec.emplace_back(a&1);
        a>>=1;
    }
    for(int i = vec.size();i>=0;i--)
        cout<<vec[i];
    cout<<endl;   
    return 0;
}
