#include<bits/stdc++.h>
using namespace std;
int length(int);
int main()
{
int n,m,z,r,e=0,k,e2,line=0;
char c[3][2]={{'I','V'},
{'X','L'},
{'C','D'}};
int num[3][2]={{1,5},{10,50},{100,500}};
string a,b;
bool f=false,f2;
while(cin>>a)
{
e=-2;
e2=-1;
if(a=="#") break;
cin>>b;
//if(line==20) {cout<<a<<" "<<b<<endl;continue;}
if(a==b) {cout<<"ZERO\n";continue;}
string h;
int x=0;
n=0,m=0;
//f2=false;
for(int i=0;i<a.length();i++)
{
f=false;
for(int j=0;j<3;j++)
{
int g;
for( g=0;g<2;g++) if(a[i]==c[j][g]){k=num[j][g];f=true;break;}
if(f)
{
if(e==-2)
{
if(i==a.length()-1) n+=k;
e=k;
}
else if(e==k) n+=e+k,e=-2;
else if(k>e)
{
n+=k-e;
e=-2;
}
else if(e>k)
{
n+=(e!=1000)*e,e=k;
if(i==a.length()-1) n+=k;
}
break;
}

}
if(f==false)
{
if(e==-2) n+=1000;
else if(e==1000) n+=1000;
else if(e==-1) n+=1000;
else if(e<1000) n+=1000-e;
else n+=1000+e;
e=1000;
}

}
//if(a.length()==1||f2) n+=e;
//cout<<n<<" ";
e=-2;
f2=false;
for(int i=0;i<b.length();i++)
{
f=false;
for(int j=0;j<3;j++)
{
int g;
for( g=0;g<2;g++) if(b[i]==c[j][g]){k=num[j][g];f=true;break;}
if(f)
{
if(e==-2)
{
if(i==b.length()-1) m+=k;
e=k;
}
else if(e==k) m+=e+k,e=-2;
else if(k>e)
{
m+=k-e;
e=-2;
}
else if(e>k)
{
m+=(e!=1000)*e,e=k;
if(i==b.length()-1) m+=k;
}
break;
}

}
if(f==false)
{
if(e==-2) m+=1000;
else if(e==1000) m+=1000;
else if(e==-1) m+=1000;
else if(e<1000) m+=1000-e;
else m+=1000+e;
e=1000;
}
// cout<<m<<" ";
}
//if(b.length()==1||f2) m+=e;
//cout<<m<<" ";
x=abs(n-m);
//x=444;
//cout<<x<<endl;
if(x==0) {cout<<"ZERO\n";continue;}
string s;
int p,l;
l=length(x);
while(l>1)
{
p=pow(10,l-1);
if(x/p==0) s+='0';
else s+=x/p+'0';
x%=p;
l--;
//cout<<s<<" ";
}
s+=x+'0';
//cout<<s<<endl;
r=0;
for(int i=s.length()-1;i>=0;i--)
{
if(s[i]=='0') {r++;continue;}
if(s.length()-i-1==3) for(int j=0;j<s[i]-'0';j++) h+='M';
else
{
if(s[i]>='5'&&s[i]<'9'){
//cout<<c[s.length()-i-1][0];
for(int mm=0;mm<(s[i]-'5');mm++) h+=c[s.length()-i-1][0];
//cout<<h.length()<<endl;
h+=c[s.length()-i-1][1];
r=0;
}
else if(s[i]=='9')
{
if(s.length()-i==3) h+='M';
else h+=c[s.length()-i][0];
h+=c[s.length()-1-i][0];
r=0;
}
else if(s[i]=='4')
{
h+=c[s.length()-i-1][1];
h+=c[s.length()-1-i][0];
r=0;
}
else
{
for(int mm=0;mm<s[i]-'0';mm++) h+=c[s.length()-i-1][0];
r=0;
}
}
}
string h2;
for(int i=h.length()-1;i>=0;i--) h2+=h[i];
/* if(h2=="MMDCCLXIII")
{
cout<<a<<"|"<<b<<endl;
continue;
}*/
cout<<h2<<endl;
}
}
int length(int n)
{
int num=1;
while(n>=10) n/=10,num++;
return num;
}