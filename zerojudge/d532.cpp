#include <iostream>
using namespace std;
int main(){
    int a,b,sum=0;
    while(cin>>a>>b){
        for(int i=a;i<=b;i++){
            sum=sum+((i%4==0&&i%100!=0)||i%400==0)%i; 
        }
        cout<<sum<<endl; 
    }
return 0;
}