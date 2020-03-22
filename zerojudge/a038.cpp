#include<bits/stdc++.h>
using namespace std;
string in;
unsigned short deletelength;
int main(){
while(cin>>in){
 char inchar[in.length()];
 strcpy(inchar,in.c_str());
 char inverse[in.length()];
 for(unsigned short lcv = 0;lcv<=in.length();lcv++)   
  inverse[lcv] = inchar[in.length()-(lcv+1)];
 for(unsigned short lcv = 0;lcv<=in.length();lcv++){  
  if(inverse[lcv] != '0'){
  deletelength = lcv;
  break;   
  }
 }
 if(deletelength == in.length()){                                                 // all zero exception
 cout<<'0'<<endl;
}
 else{
 char out[in.length()];
 for(unsigned short lcv = 0;lcv<=in.length();lcv++)  
  out[lcv] = inverse[lcv+deletelength];
  cout<<out<<endl;
}
}
return 0;
}