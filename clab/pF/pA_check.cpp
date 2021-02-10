#include <bits/stdc++.h>
using namespace std;
/*
使用教學:
把所有pA改成p[你的題目順序] 
在同個資料夾下 應該要有p[??]_sample.exe(執行p[??]_sample.cpp就會有)
那份檔案是你寫出來的正確解答
再來還要有一份pA_
*/
int main(){
    system("pA_input.exe > pA_input.txt");//產生輸入
    system("pA_sample.exe < pA_input.txt > pA_sample.txt");
    system("pA.exe < pA_input.txt > pA.txt");
    if (system("fc pA.txt pA_sample.txt")) cout << "Wrong Answer" << endl;
    else cout << "Correct" << endl;
    system("pause");
}
/*
pA. 示範題目

請將你的程式碼命名為pa.cpp 在自己電腦執行一次之後 點擊pA_check.cpp
這題會有兩個輸入a, b兩個數字用空格隔開
請輸出a+b, 並且換行
smaple input:
6 455
sample output:
461

*/