#include <bits/stdc++.h>

using namespace std;

long long n, a[3069], fq[3069];

int main() {
    long long t, rr, i, j, sm, z;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    scanf("%lld", &t);
    for (rr = 0; rr < t; rr++) {
        scanf("%lld", &n);
        for(int ll=1 ;ll<=n;ll++)
            cout<<ll<<' ';
        cout<<endl;
        for (i = 1; i <= n; i++) {
            scanf("%lld", a + i);
            fq[i] = 0;
        }
        z = 0;
        for (i = 1; i <= n; i++) {
            sm = 0;
            for (j = i + 1; j <= n; j++) {
                z += sm * (a[j] == a[i]);
                sm += fq[a[j]];
                for(int kk=1;kk<=n;kk++)    
                    cout<<fq[kk]<<' ';
                cout<<'/';
                cout<<i<<' '<<j<< ' '<< sm<<' '<<z<<endl;
                
            }
            fq[a[i]]++;
        }
        printf("%lld\n", z);
    }
}
/*
2
5
2 2 2 2 2
6
1 3 3 1 2 3
*/