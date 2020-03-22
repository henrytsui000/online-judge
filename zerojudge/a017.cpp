#include <stdio.h>
#include <stdlib.h>
char ch[100000],sym[1000];
int num[1000],i,j,k,symindex,numindex,lindex,l[100];
int main(int argc, char *argv[])
{
    while(gets(ch)!=NULL)
    {
        symindex=0,numindex=0,lindex=0;
        memset(num,0,sizeof(num));
        memset(l,0,sizeof(l));
        memset(sym,' ',sizeof(sym));
        for(i=0;i<strlen(ch);i++)
        {
            if(ch[i]==' ')
            {
                continue;
            }
            if(ch[i]>='0'&&ch[i]<='9')
            {
                num[numindex]=num[numindex]*10+(ch[i]-48);
                if(ch[i-1]=='-')
                {
                    num[numindex]*=-1;
                }
                if(ch[i+1]==' ')
                {
                    numindex++;
                }
            }
            if(ch[i]=='+'||ch[i]=='-'||ch[i]=='*'||ch[i]=='/'||ch[i]=='%'||ch[i]=='('||ch[i]==')')
            {
                switch(ch[i])
                {
                    case '+':  
                    case '-':
                    case '*':
                    case '/':
                    case '%':
                        if(ch[i+1]==' ')
                        {
                            sym[symindex]=ch[i];
                            symindex++;
                        }
                        break;
                    case '(':
                        l[lindex]=symindex;
                        lindex++;
                        break;
                    case ')':
                        Calculation(l[lindex-1]);
                        lindex--;
                        break;
                }  
            }  
        }
        Calculation(0);
        printf("%d\n",num[0]); 
    }
    return 0;
}
void Calculation(int start)
{
    for(j=start;j<=symindex;j++)
    {
        switch(sym[j])
        {
            case '*':
                num[j]*=num[j+1];
                for(k=j+1;k<=numindex;k++)
                {
                    num[k]=num[k+1];
                    sym[k-1]=sym[k];
                }
                j--;
                numindex--;
                symindex--;
                break;
            case '/':
                num[j]/=num[j+1];
                for(k=j+1;k<=numindex;k++)
                {
                    num[k]=num[k+1];
                    sym[k-1]=sym[k];
                }
                j--;
                numindex--;
                symindex--;
                break;
            case '%':
                num[j]%=num[j+1];
                for(k=j+1;k<=numindex;k++)
                {
                    num[k]=num[k+1];
                    sym[k-1]=sym[k];
                }
                j--;
                numindex--;
                symindex--;
                break;
        }
    }
    for(j=l[lindex-1];j<=symindex;j++)
    {
        switch(sym[j])
        {
            case '+':
                num[j]+=num[j+1];
                for(k=j+1;k<=numindex;k++)
                {
                    num[k]=num[k+1];
                    sym[k-1]=sym[k];
                }
                j--;
                numindex--;
                symindex--;
                break;
            case '-':
                num[j]-=num[j+1];
                for(k=j+1;k<=numindex;k++)
                {
                    num[k]=num[k+1];
                    sym[k-1]=sym[k];
                }
                j--;
                numindex--;
                symindex--;
                break;
        }
    }
}