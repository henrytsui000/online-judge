#include<bits/stdc++.h>
using namespace std;
#define MAXN 100000000
int main(){
	bool sieve[MAXN];
	int sqrt_MAXN = sqrt(MAXN),cnt=0;
    sieve[0] = sieve[1] = true;
    for (int i=2; i<=sqrt_MAXN; i++)
        if (!sieve[i])
            for (int k=(MAXN-1)/i, j=i*k; k>=i; k--, j-=i)
                if (!sieve[k]&&cnt++)
                    sieve[j] = true;
    int arr[cnt],j=0;
	for (int i=2; i<MAXN; i++)
        if (!sieve[i]&&j++)
            arr[j]=i;
	int a,b,*c,*d;
	cout<<'k'<<endl;
	while(cin>>a>>b){
		c=lower_bound(arr,arr+cnt,a);
		d=upper_bound(arr,arr+cnt,b);
		cout<<d-c<<endl;
	}
	return 0;
}
