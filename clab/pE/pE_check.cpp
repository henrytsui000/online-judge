#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

int n;
vector<int> vec;

void get_input() {
    ofstream iout("pE_input.txt");
    n = (rand() % 10 + 10);
    iout << n << endl;
    rep(i, n)
        vec.push_back(rand() % 200 - 100);
    for (int x : vec)
        iout << x << ' ';
    iout << endl;
}

void get_answer() {
    ofstream aout("pE_answer.txt");
    for (int i = n - 1; i >= 0; i--)
        if (vec[i] > 0) aout << vec[i] << ' ';
        else aout << 0 << ' ';
    aout << endl;
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
    if (flag)
        cout << "Wrong Answer" << endl;
    else
        cout << "Correct!" << endl;
    system("del pE_input.txt pE_answer.txt pE.txt");
    system("pause");
}