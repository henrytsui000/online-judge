#include <stdio.h>
using namespace std;
int main(){
	int a,j,arr[105]={0};
	scanf("%d",&a);
	for(int i=0;i<a;i++){
		scanf("%d",&j);
		arr[j]++;
	}
	for(int i=0;i<=100;i++){
		for(int k=0;k<arr[i];k++)
			printf("%d ",i+1);
	}
	
return 0;
}
