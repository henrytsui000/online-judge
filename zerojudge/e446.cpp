    #include<bits/stdc++.h>
    using namespace std;
    #define rep(i,n) for(int i=0;i<(int)n;i++)
    #define endl '\n'
    #define IOS ios_base::sync_with_stdio(0);cin.tie(0)
    #define pb emplace_back
    const int maxn = 12;
    int arr[maxn];
    int32_t main(){
        int n,r=1;
        cin>>n;
        rep(i,n) 
            arr[i]=i+1,r*=(i+1);
        do{
            rep(i,n)
                cout<<arr[i]<<' ';
            cout<<endl;
        }while(next_permutation(arr,arr+n));
        return 0;
    }
