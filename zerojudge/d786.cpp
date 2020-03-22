#include <iostream>
#include <iomanip>
using namespace std ;
int main() {
int t; cin>>t;
for(int i=1; i<=t; i++)
{
double sum=0;
int n; cin>>n;
for(int j=1; j<=n; j++)
{
int p; cin>>p;
sum+=p;
}
double ave=sum/n;
cout<<fixed<<setprecision(2)<<ave<<'\n';
}
}