#include <iostream>
using namespace std;
int main() {
	int a;
	while(cin>>a){
		int i,Friend[a],Find[a],sum=0;//sum為有幾個小團體 
		for(i=0;i<a;i++) Find[i]=0;//有無找過 0沒找過 1有找過 
		for(i=0;i<a;i++) cin>>Friend[i];
		for(i=0;i<a;i++){
			if(Find[i]==0){//沒找過的話 
				int index=i;//這裡大概的意思是用陣列裡的值去當作元素編號 
			do{
				Find[index]=1;
				index=Friend[index];
			}while(Friend[index]!=i);//找完一圈 
			Find[index]=1;//記的最後一個要標記已找過 
			sum++;
			}
		}
		cout<<sum<<endl;	
	}
	return 0;
}