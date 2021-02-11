#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

int a, b;

void get_input() {
    ofstream iout("pA_input.txt");
    a = (rand() % 101 - 50);
    b = (rand() % 101 - 50);
    iout << a <<' '<< b << endl;
}

void get_answer() {
    ofstream aout("pA_answer.txt");
    aout<<a+b<<endl;
}

int main() {
    bool flag = 0;
    srand(time(0));
    rep(i, 10) {
        get_input();
        get_answer();
        system("pA.exe < pA_input.txt > pA.txt");
        if (system("fc pA.txt pA_answer.txt")) flag = true;
    }
    if (flag) cout << "Wrong Answer" << endl;
    else cout << "Correct!" << endl;
    system("del pA_input.txt pA_answer.txt pA.txt");
    system("pause");
}