#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
long long int a,b,i,n,t,max=0,sum=1;
while(cin>>a>>b)
{
cout<<a<<" "<<b<<" ";
if(a>b) {t=a; a=b; b=t;}
for(i=a; i<=b; i++)
{
n=i;
while(n!=1)
{
sum++;
if(n%2!=0) n=3*n+1;
else n/=2;
}
if(sum>max) max=sum;
sum=1;
}
cout<<max<<endl;
max=0;
}


return 0;
}