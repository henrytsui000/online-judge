#include <stdio.h>
int main(){
	int year,i,time,Case;
	scanf("%d", &time);
	for(i=0,Case=1;i<time;i++,Case++){
		scanf("%d", &year);
		if(((year%4==0)&&(year%100!=0))||(year%400==0))	printf("Case %d: a leap year\n", Case);
		else	printf("Case %d: a normal year\n", Case);		
	}
	return 0;
}