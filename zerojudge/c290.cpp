#include <iostream>
#include <cstring>
using namespace std;
int main(){
    char X[1000];
    int diff, len;
    while(cin >> X){
        diff=0;len=strlen(X);
        for(int i = 0; i < len; i+=2) diff += X[i];
        for(int i = 1; i < len; i+=2)diff -= X[i];
        if(len%2)diff -= '0';
        if(diff < 0)diff = -diff;
        cout << diff << endl;
    }
    return 0;
}
