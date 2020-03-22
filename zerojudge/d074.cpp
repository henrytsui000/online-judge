#include <bits/stdc++.h>
int n, v[100];
int main(){
    scanf("%d", &n);  
    while(n--) scanf("%d", &v[n]);
    printf("%d", *std::max_element(v, v + 100)); 
}