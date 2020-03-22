#include<bits/stdc++.h> 
using namespace std;
int main(){	
    float con;
    int brr[31];
    for(int i=1;i<=31;i++)
            brr[i]=i*i;
    int a,b,c;
    cin>>a;
    for(int i=0;i<a;i++){
        int sum=0;
        int arr[a][4];
            cin>>arr[i][0]>>arr[i][1];
            con=sqrt(arr[i][0]);
            arr[i][2]=ceil(con);
            arr[i][3]=sqrt(arr[i][1]);
            for(int r=arr[i][2];r<=arr[i][3];r++){
            sum+=brr[r];
        }
        cout<<"Case "<<i+1<<": "<<sum<<endl;
        sum=0;	
    }
    return 0;
}