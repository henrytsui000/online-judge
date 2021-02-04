#include<bits/stdc++.h>
using namespace std;
int main(){
    system("a.out > a.txt");
    system("b.out > b.txt");
    if(system("fc a.txt b.txt"))
        cout << "fuck" <<endl;
    return 0;
}