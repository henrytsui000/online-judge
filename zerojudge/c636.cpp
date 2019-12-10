#include<bits/stdc++.h>
using namespace std;
int main()
{
string n[]={"¹«","¤û","ªê","¨ß","Às","³D","°¨","¦Ï","µU","Âû","ª¯","½Þ" };
int a,h;
while(cin>>a)
{
h=(a<12&&a>0) ?a:a%12;
h=(h>=0) ? ((h==0) ? ((a<0) ? h--:h=11):h-1):((h==-12) ? h=1:h+12);
cout<<n[h]<<endl;
}
}
