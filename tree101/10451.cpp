#include <iostream>
#include <vector>
#define LIMIT 20000 
using namespace std;

int cycle_cnt = 0;
// # of cycles in permutation


void dfs(int tmp, int here, vector<int>*adj, int* visited){
  visited[here] = 1;
  // What to do
  for(int i = 0; i < adj[here].size(); i++){
    int there = adj[here][i];
    if(!visited[there]) dfs(tmp, there, adj, visited);
    else if(there == tmp) {
      // suppose each connected component has only one cycle
      cycle_cnt++;
      break;
    }
  }
}

void dfsAll(vector<int>* adj, int* visited, int N){
  // N : size of permutation
  for(int _i = 0; _i < N; _i++){
    if(!visited[_i]) {
      dfs(_i, _i, adj, visited);
    }
  }
}

int main(){
  int K;
  cin >> K; 
  while(K--){
    cycle_cnt = 0; // initialize
    vector<int> adj[LIMIT];
    int visited[LIMIT] = {0};
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
      int to;
      cin >> to;
      adj[i - 1].push_back(to - 1);
    }
    dfsAll(adj, visited, N);
    cout << cycle_cnt << '\n';
  }
}