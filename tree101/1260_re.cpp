#include <iostream>
using namespace std;

// Q. vec<vec<int>> vs vec<list<int>>
// Q. implement by stack vs recursion
// Q. 
#include <vector>
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int here){
  visited[here] = true;
  // What to do


  for(int i = 0; i < adj[here].size(); i++){
    int there = adj[here][i];
    if(!visited[there]) dfs(there);
  }
}

void dfsAll(){
  visited = vector<bool>(adj.size(), false);
  for(int i = 0; i < adj.size(); ++i){
    if(!visited[i]) dfs(i);
  }
}

int main(){
  dfsAll();
}