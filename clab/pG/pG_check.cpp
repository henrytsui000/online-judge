#include <bits/stdc++.h>
using namespace std;
int main(){
    system("pG_sample.exe > pG_sample.txt");
    system("pG.exe > pG.txt");
    if (system("fc pG.txt pG_sample.txt")) cout << "Wrong Answer" << endl;
    else cout << "Correct" << endl;
    system("pause");
}