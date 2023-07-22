#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define LIMIT 20000
#define BIPARTITE 1
#define NOT_BIPARTITE 0

// WhichSide[i] : ith node is (1/-1) side or not discovered(0)
// => as searching, divide each node in 2 Group
int WhichSide[LIMIT] = {0};
//( V : # of vertex, E : # of sides )of Each test cases

int bfs(int start, vector<int>* adj){

  // current waiting queue for unvisited nodes
  queue<int> Q;
  // If not searched yet, It is first node of connected component as this bfs called by isBipartite
  // default = 1
  if(WhichSide[start] == 0) WhichSide[start] = 1;
  Q.push(start);
  while(!Q.empty()){
    int here = Q.front();
    Q.pop();
    for(int i = 0; i < adj[here].size(); i++){
      int there = adj[here][i];
      if(!WhichSide[there]){
        // discover there & add it to queue
        // assign adjoint nodes to different group of [here]
        Q.push(there);
        WhichSide[there] = -WhichSide[here];
      }
      // if "there" is same group as "here", it is not bipartite
      else if(WhichSide[there] == WhichSide[here]) return NOT_BIPARTITE;
    }
  }
  return BIPARTITE;
}

int main(){
  int K; // # of test cases
  cin >> K;
  for(int _i = 0; _i < K; _i++){
    int V, E;
    cin >> V >> E;

    fill_n(WhichSide, V, 0);
    // adj[i] : array of vector of indexes of adjoint nodes.
    vector<int> adj[LIMIT];

    for(int i = 0; i < E; i++){
      int from, to;
      cin >> from >> to;
      adj[from - 1].push_back(to - 1);
      adj[to - 1].push_back(from - 1);
    }

    int isBipartite = 1;
    for (int i = 0; i < V; i++)
    {
      if (WhichSide[i] != 0)
        continue;
      if (bfs(i, adj) == NOT_BIPARTITE)
        isBipartite = 0;
    }
    cout << ((isBipartite == 1)? "YES" : "NO")<< '\n';
  }
}