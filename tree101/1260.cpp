#include <iostream>
#include <queue>
#define LIMIT 1000
using namespace std;
int G[LIMIT + 1][LIMIT + 1] = {0};

void dfs(int v, int *visited, int size){
  visited[v] = 1;
  cout << v + 1 << " ";
  for(int i = 0; i < size; i++)
    if(G[v][i] == 1 && visited[i] == 0) dfs(i, visited, size);
}

void bfs(int v, int* visited, int size){
  queue<int> Q;
  visited[v] = 1;
  Q.push(v);

  while(!Q.empty()){
    v = Q.front();
    Q.pop();
    cout << v + 1 << " ";
    for(int i = 0; i < size; i++){
      if(G[v][i] == 1 && visited[i] == 0){
        Q.push(i);
        visited[i] = 1;
      }
    }
  }
}


int main(){
  int N, M, V, i, j;
  cin >> N >> M >> V;
  for(int _i = 0; _i < M; _i++){
    cin >> i >> j;
    G[i - 1][j - 1] = 1;
    G[j - 1][i - 1] = 1;
  }

  int dfs_visited[LIMIT] = {0};
  // DFS
  dfs(V - 1, dfs_visited, N);
  cout << '\n';

  int bfs_visited[LIMIT] = {0};
  // BFS
  bfs(V - 1, bfs_visited, N);
}