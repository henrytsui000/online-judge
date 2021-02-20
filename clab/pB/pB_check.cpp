#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

int a, b;

void get_input() {
    ofstream iout("pB_input.txt");
    a = (rand() % 101 - 50);
    b = (rand() % 101 - 50);
    iout << a <<' '<< b << endl;
}

void get_answer() {
    ofstream aout("pB_answer.txt");
    aout<<a+b<<endl;
}

int main() {
    bool flag = 0;
    srand(time(0));
    rep(i, 10) {
        get_input();
        get_answer();
        system("pB.exe < pB_input.txt > pB.txt");
        if (system("fc pB.txt pB_answer.txt")) flag = true;
    }
    if (flag) cout << "Wrong Answer" << endl;
    else cout << "Correct!" << endl;
    system("del pB_input.txt pB_answer.txt pB.txt");
    system("pause");
}