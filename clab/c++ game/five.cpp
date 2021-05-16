#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define maxn 10
#define in_range(i, j) (i >= 0 && i < maxn && j >= 0 && j < maxn)

int graph[maxn][maxn];
// graph[x][y]
// 1,1 1,2 1,3 1,4 1,5
// 2,1 2,2 2,3  
// 3,1 3,2 3,3
// 4
// 5

// 2 ¤U f(2) = 0 dx =  1, dy =  0
// 4 ¥ª 1 dx =  0, dy = -1
// 6 ¥k 2 dx =  0, dy =  1
// 8 ¤W 3 dx = -1, dy =  0
clock_t last_time;
int dx_for_move[4] = { 1, 0, 0,-1};
int dy_for_move[4] = { 0,-1, 1, 0};
int dx_for_check[8] = {-5,-5, 0, 5, 5, 5, 0,-5};
int dy_for_check[8] = { 0, 5, 5, 5, 0,-5,-5,-5};
int now_pointer_x, now_pointer_y, whos_turn, move_direction;
stack< pair<int, int > > recover;

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


int check_win(int x, int y){
    for(int k = 0; k < 8 ; k++){
        int count_to_check_five = 0;
        for(int i = x, j = y, cnt = 0; cnt < 5 && in_range(i, j); i += dx_for_check[k]/5, j += dy_for_check[k]/5, cnt++){
            count_to_check_five += graph[i][j];
            if(abs(count_to_check_five) == 5){
                return count_to_check_five/5;
            }
        }
    }
    return 0;
}

int show(){
    new_screen(0, 0);
    for(int i = 0; i < 2 * maxn +1 ; i++){
        for(int j = 0; j < 2 * maxn + 1;j++){
            if(i == 0 && j == 0)                     cout<<" ùÝ";
            else if(i == 0 && j == 2 * maxn)         cout<<"ùß";
            else if(i == maxn * 2 && j == 0)         cout<<" ùã";
            else if(i == maxn * 2 && j == maxn * 2 ) cout<<"ùå";
            else if(i % 2 == 0 && j == 0)            cout<<" ùà";
            else if(i % 2 == 0 && j == maxn * 2)     cout<<"ùâ";
            else if(j % 2 == 1 && i % 2 == 0)        cout<<"¢¤¢¤¢¤";
            else if(i == 0 && j % 2 == 0)            cout<<"ùÞ";
            else if(i == 2 * maxn && j % 2 == 0)     cout<<"ùä";
            else if(i % 2 == 0 && j % 2 == 0)        cout<<"ùá";
            else if(j % 2 == 0)                      cout<<" ùø";
            else if(i == now_pointer_x * 2 + 1 && j == now_pointer_y * 2 + 1) cout<<" X";
            else if(graph[i/2][j/2] == 1)                cout<<"¡´";
            else if(graph[i/2][j/2] == -1)               cout<<"¡³";
            else cout<<"  ";
        }
        if(i == 5)      cout << "\t2 4 6 8 to control";
        else if(i == 6) cout << "\t5 to select";
        else if(i == 7) cout << "\tq to quit";
        else if(i == 8) cout << "\tr to recover";
        else if(i == 9) cout << "\tn to new game";
        cout<<endl;
    }
}

void deb(){  
    system("cls");
    rep(i,maxn){
        rep(j,maxn)
            cout<<graph[i][j]<<' ';
        cout<<endl;
    }
    Sleep(2000);
}

void start() {
    whos_turn = 1;
    char key;
    now_pointer_x = now_pointer_y = move_direction = 0;
    while (true) {
        bool che = false;
        if (kbhit()) {
            key = getch();
            if((key == '2')||(key == '4')||(key == '6')||(key == '8')){
                move_direction = (key - '0') / 2 -1;
                int next_x = now_pointer_x + dx_for_move[move_direction], next_y = now_pointer_y + dy_for_move[move_direction];
                if( in_range(next_x, next_y) && ((double)(clock() - last_time)/ CLOCKS_PER_SEC > 0.1)){
                    while(in_range(next_x, next_y) && graph[next_x][next_y] != 0) 
                        next_x += dx_for_move[move_direction], next_y += dy_for_move[move_direction];
                    if( in_range(next_x, next_y) )
                        now_pointer_x = next_x, now_pointer_y = next_y, last_time = clock();
                }
            }else if(key == 'q'){
                return;
            }else if (key == '5'&& ((double)(clock() - last_time)/ CLOCKS_PER_SEC > 0.1)){
                graph[now_pointer_x][now_pointer_y] = whos_turn;
                whos_turn *= -1;
                last_time = clock();
                show();
                rep(i, maxn) rep(j, maxn){
                    int who_win = check_win(i, j);
                    if(who_win == 1){
                        cout<<" _______  __  .______          _______.___________.   .______    __          ___   ____    ____  _______ .______         ____    __    ____  __  .__   __.  __  ";
                        cout<<"\n|   ____||  | |   _  \\        /       |           |   |   _  \\  |  |        /   \\  \\   \\  /   / |   ____||   _  \\        \\   \\  /  \\  /   / |  | |  \\ |  | |  | ";
                        cout<<"\n|  |__   |  | |  |_)  |      |   (----`---|  |----`   |  |_)  | |  |       /  ^  \\  \\   \\/   /  |  |__   |  |_)  |        \\   \\/    \\/   /  |  | |   \\|  | |  | ";
                        cout<<"\n|   __|  |  | |      /        \\   \\       |  |        |   ___/  |  |      /  /_\\  \\  \\_    _/   |   __|  |      /          \\            /   |  | |  . `  | |  | ";
                        cout<<"\n|  |     |  | |  |\\  \\----.----)   |      |  |        |  |      |  `----./  _____  \\   |  |     |  |____ |  |\\  \\----.      \\    /\\    /    |  | |  |\\   | |__| ";
                        cout<<"\n|__|     |__| | _| `._____|_______/       |__|        | _|      |_______/__/     \\__\\  |__|     |_______|| _| `._____|       \\__/  \\__/     |__| |__| \\__| (__) ";
                        return ;
                    }else if(who_win == -1){
                        cout<<"\n     _______. _______   ______   ______   .__   __.  _______     .______    __          ___   ____    ____  _______ .______         ____    __    ____  __  .__   __.  __  ";
                        cout<<"\n    /       ||   ____| /      | /  __  \\  |  \\ |  | |       \\    |   _  \\  |  |        /   \\  \\   \\  /   / |   ____||   _  \\        \\   \\  /  \\  /   / |  | |  \\ |  | |  | ";
                        cout<<"\n   |   (----`|  |__   |  ,----'|  |  |  | |   \\|  | |  .--.  |   |  |_)  | |  |       /  ^  \\  \\   \\/   /  |  |__   |  |_)  |        \\   \\/    \\/   /  |  | |   \\|  | |  | ";
                        cout<<"\n    \\   \\    |   __|  |  |     |  |  |  | |  . `  | |  |  |  |   |   ___/  |  |      /  /_\\  \\  \\_    _/   |   __|  |      /          \\            /   |  | |  . `  | |  | ";
                        cout<<"\n.----)   |   |  |____ |  `----.|  `--'  | |  |\\   | |  '--'  |   |  |      |  `----./  _____  \\   |  |     |  |____ |  |\\  \\----.      \\    /\\    /    |  | |  |\\   | |__| ";
                        cout<<"\n|_______/    |_______| \\______| \\______/  |__| \\__| |_______/    | _|      |_______/__/     \\__\\  |__|     |_______|| _| `._____|       \\__/  \\__/     |__| |__| \\__| (__) ";
                        return ;
                    }
                }
                recover.push(make_pair(now_pointer_x, now_pointer_y));
                now_pointer_x = now_pointer_y = 0;
            }else if(key == 'r'){
                che = true;
                if(recover.size() == 0){    
                    system("cls");
                    cout<<"fuck u\n";
                    Sleep(1000);
                }else{
                    graph[recover.top().first][recover.top().second] = 0;
                    recover.pop();
                    whos_turn *= -1;
                    now_pointer_x = now_pointer_y = 0;
                    last_time = clock();
                }
            }else if(key == 'n'){
                string str;
                system("cls");
                cout<<"New game? Y/n"<<endl;
                cin>>str;
                if(str == "Y"){
                    rep(i,maxn)
                        rep(j,maxn)
                            graph[i][j] = 0;
                    whos_turn = 1;
                    now_pointer_x = now_pointer_y = 0;
                }
            }
        }
        show();
        cout<<key<<endl;
    }
}

void show_rule(){
    cout << "2 4 6 8 to control x\n";
    cout << "5 to select\n";
    cout << "q to quit\n";
    cout << "r to recover\n";
    cout << "n to new game\n";
    system("pause");
}

// ùÝ ùß ùã ùå ùà ùâ ùá ¢¤
int main(){
    last_time = clock();
    show_rule();
    start();
    return 0;
}
//¡³¡´
