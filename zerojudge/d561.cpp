#include <bits/stdc++.h>
using namespace std;
int main(){
    int i,dot;
    char s[105];
    while(scanf("%s",s)==1){
        for(i=0;s[i]!='.';i++);
        dot = i;
        if(s[dot+3]>'4') s[dot+2]++;
        for(i=dot+2;i>-1;i--)
            if(s[i]!='.' && s[i]!='-')
                if(s[i]==58){
                    s[i] = 48;
                    if(s[i-1] != '.') s[i-1]++;
                    else s[i-2]++;
                }else break;
        s[dot+3] = '\0';
        if(s[1]==s[3] && s[3]==s[4] && s[4]=='0')
            printf("%s\n",s+1);
        else printf("%s\n",s);
    }
    return 0;
}