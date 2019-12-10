//��J��X�u��
#include<bits/stdc++.h>
using namespace std;
ios_base::sync_with_stdio(0);
cin.tie(0);
#define endl '\n' 

//�ֳt�� 
int pow3(int a,int b){
    int ans = 1,base = a;
    while(b!=0){
        if(b&1)
            ans *= base;
        base *= base;
        b>>=1;
    }
    return ans;
}

//�u�ʿz�� 
bool sieve[MAXN];
vector<int> prime;
void linear_prime(){
	for(int i=2;i<MAXN;i++){
		if(!sieve[i])
			prime.push_back(i);
		for(int j=0;prime[j]*i<MAXN;j++){
			sieve[i*prime[j]]=true;
			if(i%prime[j]==0)
				break;
		}
	}
}

//DP-�I�]���D 
/*f[]���̤j����
v�O�e�n
totv�O�̤j��n 
v[i]�O���~�j�p
p[i]�O����*/ 

for(int i=1;i<=n;i++)
  for (v=totv;v>=v[i];v--)
    f[v]=max(f[v],f[v-v[i]]+p[i]);
cout<<f[totv];






//DFS
#define graph 9
bool adj[graph][graph];
bool visit[graph];
void DFS(int i){
	visit[i]=true;
	for(int j=0;j<graph;j++)
		if(adj[i][j]&&!visit[j])
			DFS(j); 
} 
void traveral(){
	for(int i=0;i<graph;i++)
		visit=false;
	for(int i=0;i<graph;i++)
		if(!visit)
			DFS(i);
}

//BFS
#define graph 9
bool adj[graph][graph];
bool visit[graph];
void BFS(){
	queue<int> q;
	for(int i=0;i<graph;i++)
		visit=false;
	for(int k=0;k<graph;k++)
		if(!visit){
			q.push(k);
			visit[i]=true;
			while(!q.empty()){
				int i=q.front();q.pop();
				for(int j=0;j<graph;j++)
					if(adj[i][j]&&!visit[j]){
						q.push(j);
						visit=true;
					}
			}
		}	
}		

//�j�Ʀs��
void scan(char s[100], int a[100]){
    int i = 100 - 1;            // �j�ƪ��Ʀr��m
    int j = 0, n = strlen(s);   // �r�ꪺ�r����m
    while (i >= n) a[i--] = 0;  // �}�Y�@�߶�s
    while (i >= 0) a[i--] = s[j++] - '0';   // �r���Y���A�ˡA�s�J�}�C
} 

//�j�ư��k
void div(int a[100], int b[100], int c[100]){
    int t[100];
 
    for (int i=100-1; i>=0; i--)
        for (int k=9; k>0; k--){ // ���հӼ�
            mul(b+i, k, t);
            if (largerthan(a+i, t)){
                sub(a+i, t, c+i);
                break;
            }
        }
} 

//�G���j�M 
int binary_search(int left, int right, int pivot){
    while (left <= right){
        int mid = (left + right) / 2;
        if (array[mid] < pivot)
            left = mid + 1;
        else if (array[mid] > pivot)
            right = mid - 1;
        else if (array[mid] == pivot)
            return mid;
    }
    return left;    // �p�G�䤣��A�N�^�ǵy�j�@�I���ƭȦ�m�C
}
