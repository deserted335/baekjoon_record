#include <iostream>
using namespace std;
#include <vector>
vector<vector<int>> adj(
  100,
  vector<int>(100)
);
vector<bool> visited(100);
int cnt = 0, N;

void dfs(int here){
  visited[here] = true;
  // visiting, count += 1;
  cnt++;
  for(int i = 0; i < N; i++)
    if(adj[here][i] == 1 && !visited[i]) dfs(i);
}

int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int T;
  cin >> N >> T;
  for(int i = 0; i < T; i++){
    int from, to;
    cin >> from >> to;
    adj[from - 1][to - 1] = 1;
    adj[to - 1][from - 1] = 1;
  }

  dfs(0);
  cout << cnt - 1;
}