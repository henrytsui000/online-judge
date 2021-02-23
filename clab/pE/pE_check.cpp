#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

int a, b;

void get_input() {
    ofstream iout("pE_input.txt");
    a = (rand() % 11 + 1);
    b = (rand() % 5);
    iout << a <<' '<< b << endl;
}

int fab(int n){
    if(n)   return n * fab(n-1);
    else return 1;
}

void get_answer() {
    ofstream aout("pE_answer.txt");
    aout << (int)(pow(a, b) + 0.5) + (fab(a) / fab(b))<<endl;
}

int main() {
    bool flag = 0;
    srand(time(0));
    rep(i, 10) {
        get_input();
        get_answer();
        system("pE.exe < pE_input.txt > pE.txt");
        if (system("fc pE.txt pE_answer.txt")) flag = true;
    }
    if (flag) cout << "Wrong Answer" << endl;
    else cout << "Correct!" << endl;
    system("del pE_input.txt pE_answer.txt pE.txt");
    system("pause");
}