#include<stdio.h>
#include<string.h>
int main(){
int i,j;
char a[1000],temp;
while(scanf("%s",a)!=EOF){
puts(a);
for(i=0;i<strlen(a)-1;i++){
temp=a[0];
for(j=1;j<strlen(a);j++){
a[j-1]=a[j];
}
a[strlen(a)-1]=temp;
puts(a); 
}

}
}