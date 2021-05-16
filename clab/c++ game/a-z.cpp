#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;

void new_screen(int xpos, int ypos) {
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = xpos, scrn.Y = ypos;
    SetConsoleCursorPosition(hOuput, scrn);
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle, &CursorInfo);
    CursorInfo.bVisible = false;
    SetConsoleCursorInfo(handle, &CursorInfo);
}

void start() {
    char key;
    while (true) {
        if (kbhit()) {
			key = getchar();
			cout << key << endl;
        }
		new_screen(0, 0);
    }
}

int main(){
    start();
    return 0;
}

//?