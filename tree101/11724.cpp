#include <iostream>
#include <vector>
#define LIMIT 1000
using namespace std;
int adj[LIMIT][LIMIT] = {0};
bool visited[LIMIT] = {0};
int N, M;
int cnt_cnt = 0;


void dfs(int here){
  visited[here] = true;
  // What to do
  for(int i = 0; i < N; i++){
    int isConnected = adj[here][i];
    if(!visited[i] && isConnected) dfs(i);
  }
}

void dfsAll(){
  for(int _i = 0; _i < N; _i++){
    if(!visited[_i]) {
      dfs(_i);
      cnt_cnt++;
    }
  }
}

int main(){
  cin >> N >> M;
  for(int i = 0; i < M; i++){
    int from, to;
    cin >> from >> to;
    adj[from - 1][to - 1] = 1;
    adj[to - 1][from - 1] = 1; 
  }
  dfsAll();
  cout << cnt_cnt;
}