#include<bits/stdc++.h>
using namespace std;
vector<int> arr;
#define MAX 1000000
int check();
int main(){
	int a,b,p,q;
	check();
	while(cin>>a>>b){
	bool rec=1;
		int aNum,bNum;
        aNum = bNum = 0;
        
        int p,q;
        p = 0;
        q = arr.size()-1;
        while(p<=q){
            int mid = (p+q)/2;
            if(arr[mid] <= a-1){
                aNum = max(aNum,mid+1);
                p = mid+1;
            }
            else{
                q = mid-1;
            }
        }
        
        p = 0;
        q = arr.size()-1;
        while(p<=q){
            int mid = (p+q)/2;
            if(arr[mid] <= b){
                bNum = max(bNum,mid+1);
                p = mid+1;
            }
            else{
                q = mid-1;
            }
        }
        for(int i=aNum;i<=bNum-1;i++){
        	cout<<arr[i]<<' ';
        	rec=false;
		}
		if(rec)cout<<"none";
		cout<<endl;
		rec=true;
	}
	
	return 0;
} 
int check(){
	int k,sum=0,v,n=0;
	for(int i=1;i<MAX;i++){
		k=i;
		v=i;
		while(v!=0){
			n++;
			v/=10;
		}
		while(k!=0){
			sum+=pow(k%10,n);
			k/=10;
		}
		if(sum==i){
			arr.push_back(i);
		}
		sum=0;n=0;
	}
}