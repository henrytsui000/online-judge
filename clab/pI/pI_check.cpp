#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

int r, c;

int a[105][105];
void get_input() {
    ofstream iout("pI_input.txt");
    r = (rand() % 100 + 1);
    c = (rand() % 100 + 1);
    iout << r << ' ' << c << endl;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            a[i][j] = (rand() % 10);
            iout << a[i][j] << ' ';
        }
        iout << endl;
    }
}

void get_answer() {
    ofstream aout("pI_answer.txt");
    for (int i = 1; i <= c; i++) {
        for (int j = 1; j <= r; j++) {
            aout << a[j][i] << " ";
        }
        aout << endl;
    }
}

int main() {
    bool flag = 0;
    srand(time(0));
    rep(i, 10) {
        get_input();
        get_answer();
        system("pI.exe < pI_input.txt > pI.txt");
        if (system("fc pI.txt pI_answer.txt")) flag = true;
    }
    if (flag)
        cout << "Wrong Answer" << endl;
    else
        cout << "Correct!" << endl;
    system("del pI_input.txt pI_answer.txt pI.txt");
    system("pause");
}
