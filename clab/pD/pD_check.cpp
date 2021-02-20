#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

int a, b;

void get_input() {
    ofstream iout("pD_input.txt");
    a = (rand() % 101);
    b = (rand() % (a+1));
    iout << a <<' '<< b << endl;
}

void get_answer() {
    ofstream aout("pD_answer.txt");
    for(int i = 0 ; i <= 1000;i++)
        if(i*a > b*1000){
            aout<<i-1<<endl;
            break;
        }
}

int main() {
    bool flag = 0;
    srand(time(0));
    rep(i, 10) {
        get_input();
        get_answer();
        system("pD.exe < pD_input.txt > pD.txt");
        if (system("fc pD.txt pD_answer.txt")) flag = true;
    }
    if (flag) cout << "Wrong Answer" << endl;
    else cout << "Correct!" << endl;
    system("del pD_input.txt pD_answer.txt pD.txt");
    system("pause");
}