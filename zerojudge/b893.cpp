#include<bits/stdc++.h>
using namespace std;
int arr[6];
int pow(int a,int b){
    int ans = 1,base = a;
    while(b!=0){
        if(b&1)
            ans *= base;
        base *= base;
        b>>=1;
    }
    return ans;
}
int sum(int k){
	int cnt=0;
	for(int i=5;i>=0;i--)
		cnt+=pow(k,i)*arr[i];
	return cnt;
}
int main(){
	for(int i=0;i<6;i++){
		cin>>arr[i];
	}
	int N=0;
	
	for(int i=-40;i<=40;i++){
		if(sum(i)==0){
			cout<<i<<' '<<i<<endl;
			N=0;
		}else if(sum(i)<0){
			if(N==1)cout<<i<<' '<<i+1;
			N=-1;
		}else{
			if(N==-1)cout<<i<<' '<<i<<endl;
			N=1;
		}
	}
	
	
	return 0;
}
