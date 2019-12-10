#include<bits/stdc++.h> 
using namespace std;
int main(){
	string ch;
	int i=1;
	while(cin>>ch){
		if(ch=="#")break;
		cout<<"Case "<<i<<": ";
		if(ch=="HELLO") cout<<"ENGLISH"<<endl;
		else if(ch=="HOLA")	cout<<"SPANISH"<<endl;
		else if(ch=="HALLO") cout<<"GERMAN"<<endl;
		else if(ch=="BONJOUR") cout<<"FRENCH"<<endl;
		else if(ch=="CIAO")	cout<<"ITALIAN"<<endl;
		else if(ch=="ZDRAVSTVUJTE")	cout<<"RUSSIAN"<<endl;
		else cout<<"UNKNOWN"<<endl;
		i++;
		}
	return 0;
}
