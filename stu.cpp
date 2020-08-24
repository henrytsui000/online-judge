#include <bits/stdc++.h>
using namespace std;
void sort(int *start, int *end){
    int *minP = start;
    int *p = start;
    int t;
    
	for(int *i=start; i!=end;i++){
		if(*start>*i){
			t = *start;
			*start = *i;
			*i = t;
		}
	}
	sort(start+1,end);
}

int main(void){
    int a[]={6,5,7,3,2,0,1};
    int i=0;
    sort(a,a+6);
    for(i=0;i<7;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}