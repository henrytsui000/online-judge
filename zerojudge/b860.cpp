#include<bits/stdc++.h>
using namespace std;
int num(int ,int);
int num(int n,int m)
{
	if (m==0) return 0;
	int s=0,z=m;
	if(n/12>=m) return m;
	while(n+m>=0)
	{
	
		if(m<=0) return s;
		if(n<12) 
		{
			m-=(12-n);
			/*if(z<0) 
			{
				m+=z;
				z=0;
			}*/
			n=12;
		}
		else 
		{	
			s++;
			//z+=n/12;
			m--;
			//s++;
			n-=10; 
		}
		//cout<<n<<endl<<s<<endl<<m<<endl;
	}
	return s;
}
int main()
{
	int n,m,z=0;
	while(cin>>n>>m)
	{
		int nu=num(n,m);
		cout<<nu<<endl;
	}
}