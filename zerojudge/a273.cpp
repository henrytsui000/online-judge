#include<iostream>
using namespace std;
int main()
{
int x,y=0;
while(cin>>x>>y) 
{
if(x==0&&y==0)
{
cout<<"Ok!"; goto Exit;
}
if(y==0){
cout<<"Impossib1e!"; goto Exit;
}

x%y==0 ? cout<<"Ok!" : cout<<"Impossib1e!" ;
Exit:
cout<<endl;
}

}
