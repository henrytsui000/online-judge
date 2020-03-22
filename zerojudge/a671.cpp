#include<stdio.h>
#include<math.h>
#define MY_E 2.718281828459
int main(){
double n, p;

while(scanf("%lf%lf",&n ,&p) != EOF)
     printf("%d\n", (int)(pow(MY_E, log(p)/n) + 0.5));
return 0;
}