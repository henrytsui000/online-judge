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
                cout<<"�Ӧ����F��!�����Q���ڦ��I\n";
        else
                cout<<"���ˤj�H!���ˤj�H!�ڧ֨�F�I\n";
            }
            return 0;
        }
