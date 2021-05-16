#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;
#define rep(i,n) for(int i = 0;i < (int)n;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'

const int maxn = 10;
int graph[maxn][maxn];
int hd_x, hd_y;
int dir = 2;
clock_t nt;
int dx[4] = { 1, 0, 0,-1};
int dy[4] = { 0,-1, 1, 0};
int eat_x, eat_y;
int sl = 5;

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

void init(){
    rep(i,maxn) rep(j,maxn)
        graph[i][j] = 0;
    rep(i,5)
        graph[5][i+2] = i + 1;
    hd_x = 5, hd_y = 6;
}

void renew(){
    rep(i,maxn) rep(j,maxn)
        if(graph[i][j]) graph[i][j]--;
}

void eat(){
    do{
        eat_x = rand()%maxn;
        eat_y = rand()%maxn;
    }while(graph[eat_x][eat_y]);
    cout<<"check: ";
    cout<<eat_x<<' '<<eat_y<<endl;
}

void show(){
    new_screen(0, 0);
    rep(i,maxn){
        rep(j,maxn){
            if(graph[i][j]>0)
                cout<<"S";
            else if(i == eat_x && j == eat_y)
                cout<<"B";
            else
                cout<<" ";
            // cout<<graph[i][j];
        }
        cout<<endl;
    }
    cout<<dir<<endl;
    cout<<time(0)<<endl;
    cout<<"staff: "<<eat_x<<' '<<eat_y<<endl;
    cout<<setw(2)<<hd_x<<' '<<hd_y<<endl;
}

void GG(){
    new_screen(0,0);
    rep(i,maxn){
        rep(j,maxn)
            if(graph[i][j])
                cout<<"D";
            else cout<<" ";
        cout<<endl;
    }
    Sleep(3000);
    cout<<"\n   _____                         ____                 ";
    cout<<"\n  / ____|                       / __ \\                ";
    cout<<"\n | |  __  __ _ _ __ ___   ___  | |  | |_   _____ _ __ ";
    cout<<"\n | | |_ |/ _` | '_ ` _ \\ / _ \\ | |  | \\ \\ / / _ \\ '__|";
    cout<<"\n | |__| | (_| | | | | | |  __/ | |__| |\\ V /  __/ |   ";
    cout<<"\n  \\_____|\\__,_|_| |_| |_|\\___|  \\____/  \\_/ \\___|_|   ";
    cout<<"\n                         ";
    Sleep(3000);
}

void start() {
    eat();
    nt = clock();
    char key;
    while (true) {
        if (kbhit()) {
            key = getch();
            if( key - '0' < 9 && key - '0' > 1){
                int act = (key - '0') /2 -1;
                if(dir + act != 3)
                    dir = act;
            }
        }
        show();
        printf("dir : %d\n",dir);
        if(((double)(clock() - nt)/ CLOCKS_PER_SEC > 0.5)){
            hd_x += dx[dir], hd_y += dy[dir];
            hd_x = (hd_x + maxn)%maxn, hd_y = (hd_y + maxn )%maxn;
            if(graph[hd_x][hd_y]){
                GG();
                return ;
            }else if(hd_x == eat_x && hd_y == eat_y){
                sl++; 
                eat();
            }else{
                renew();
            }
            graph[hd_x][hd_y] = sl;
            nt = clock();
        }
    }
}

int main(){
    srand(time(NULL));
    init();
    show();
    start();
    return 0;
}

//?