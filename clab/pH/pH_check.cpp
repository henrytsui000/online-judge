#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

int a, b;

void get_input() {
    ofstream iout("pH_input.txt");
    a = (rand() % 10000);
    b = (rand() % 10000);
    iout << a <<' '<< b << endl;
}

void get_answer() {
    ofstream aout("pH_answer.txt");
    aout<<(a*b)/__gcd(a,b)<<endl;
}

int main() {
    bool flag = 0;
    srand(time(0));
    rep(i, 10) {
        get_input();
        get_answer();
        system("pH.exe < pH_input.txt > pH.txt");
        if (system("fc pH.txt pH_answer.txt")) flag = true;
    }
    if (flag) cout << "Wrong Answer" << endl;
    else cout << "Correct!" << endl;
    system("del pH_input.txt pH_answer.txt pH.txt");
    system("pause");
}