#include<iostream>
using namespace std;
int main (){
    int x1,x2,x3,y1,y2,y3,N,i;
    cin>>N; 
    for(i=0;i<N;i++){
       cin>>x1>>y1>>x2>>y2>>x3>>y3;
        if(((x1-x2)*(y1-y3))==((y1-y2)*(x1-x3)) &&
           ((x1<=x3 && x3<=x2 && y1<=y3 && y3<=y2) ||
            (x1>=x3 && x3>=x2 && y1>=y3 && y3>=y2) ||
            (x1<=x3 && x3<=x2 && y1>=y3 && y3>=y2) ||
            (x1>=x3 && x3>=x2 && y1<=y3 && y3<=y2) ))
                cout<<"該死的東西!竟敢想讓我死！\n";
        else
                cout<<"父親大人!母親大人!我快到了！\n";
            }
            return 0;
        }
