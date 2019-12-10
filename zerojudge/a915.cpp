#include<bits/stdc++.h>
using namespace std;
int main(){
	int a;
	cin>>a;
	long arr[a][2],ANS;
	long long brr[a];
	for(int i=0;i<a;i++){
	cin>>arr[i][0]>>arr[i][1];
	brr[i]=arr[i][0]*100001+arr[i][1];
}
	sort(brr,brr+a);
	for(int i=0;i<a;i++){
		ANS=brr[i]/100001;
		cout<<ANS<<' '<<brr[i]%100001<<endl;
	}
	return 0;
} 
