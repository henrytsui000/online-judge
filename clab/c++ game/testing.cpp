#include <bits/stdc++.h>
#include<windows.h>
using namespace std;

void new_screen(int xpos, int ypos) {
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = xpos, scrn.Y = ypos;
    SetConsoleCursorPosition(hOuput, scrn);
}
int32_t main(){
    int i = 0;
    while(i < 10){
        new_screen(0,0);
        cout<<i<<endl;
        i++;
        Sleep(1000);
    }
    
    return 0;
}