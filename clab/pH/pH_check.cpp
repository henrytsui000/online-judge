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
    if (n >= 90)
        aout << 4.3 << endl;
    else if (n >= 85)
        aout << 4 << endl;
    else if (n >= 80)
        aout << 3.7 << endl;
    else if (n >= 77)
        aout << 3.3 << endl;
    else if (n >= 73)
        aout << 3 << endl;
    else if (n >= 70)
        aout << 2.7 << endl;
    else if (n >= 67)
        aout << 2.3 << endl;
    else if (n >= 63)
        aout << 2 << endl;
    else if (n >= 60)
        aout << 1.7 << endl;
    else
        aout << 0 << endl;
}

int main() {
    srand(time(0));
    bool flag = 0;
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