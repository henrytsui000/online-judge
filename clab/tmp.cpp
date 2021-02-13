#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

int n;

void get_input() {
    ofstream iout("pH_input.txt");
    n = (rand() % 40 + 50);
    iout << n << endl;
}

void get_answer() {
    ofstream aout("pH_answer.txt");
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