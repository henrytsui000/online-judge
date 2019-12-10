#include<bits/stdc++.h>
using namespace std;
int cnt=0;
int main(){
	int a,x,y,ANS=0;
	cin>>a;
	static bool k[a-1];
	static bool arr[a-1][a-1];

	for(int i=1;i<a;i++){
		cin>>x>>y;
		arr[x][y]=true;
	}
	
    for (int i=0; i<9; i++)
        if (!k[i]){
            k[i] = true;
            DFS(i);
            if(ANS<cnt)ANS=cnt;
        }
    cout<<ANS<<endl;
	return 0;	
}
int DFS(int i){
    for (int j=0; j<9; j++)
        if (arr[i][j] && !k[j]){
            k[j] = true;    // 標記為已遍歷
            cnt++;
            DFS(j);
        }
}
