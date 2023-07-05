// // recursive DFS with adjoint matrix.
// #include <vector>
// #define LIMIT 1000
// using namespace std;
// int adj[LIMIT][LIMIT] = {0};
// bool visited[LIMIT] = {0};
// int N, M;
// int cnt_cnt = 0;


// void dfs(int here){
//   visited[here] = true;
//   // What to do
//   for(int i = 0; i < N; i++){
//     int isConnected = adj[here][i];
//     if(!visited[i] && isConnected) dfs(i);
//   }
// }

// void dfsAll(){
//   for(int _i = 0; _i < N; _i++){
//     if(!visited[_i]) {
//       dfs(_i);
//       cnt_cnt++;
//     }
//   }
// }

// int main(){
//   cin >> N >> M;
//   for(int i = 0; i < M; i++){
//     int from, to;
//     cin >> from >> to;
//     adj[from - 1][to - 1] = 1;
//     adj[to - 1][from - 1] = 1; 
//   }
//   dfsAll();
//   cout << cnt_cnt;
// }

// // recursion DFS with 
// #include <vector>
// #define LIMIT 20000 
// using namespace std;
// vector<vector<int>>adj(LIMIT, vector<int>(0, 0));
// bool visited[LIMIT] = {0};
// int N, M;
// int cnt_cnt = 0;


// void dfs(int here){
//   visited[here] = true;
//   // What to do
//   for(int i = 0; i < adj[here].size(); i++){
//     int there = adj[here][i];
//     if(!visited[there]) dfs(there);
//   }
// }

// void dfsAll(){
//   for(int _i = 0; _i < N; _i++){
//     if(!visited[_i]) {
//       dfs(_i);
//       cnt_cnt++;
//     }
//   }
// }

// int main(){
//   cin >> N >> M;
//   for(int i = 0; i < M; i++){
//     int from, to;
//     cin >> from >> to;
//     adj[from - 1].push_back(to - 1);
//     adj[to - 1].push_back(from - 1);
//   }
//   dfsAll();
//   cout << cnt_cnt;
// }

// // bfs
// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;
// #define LIMIT 1000
// vector<vector<int>>adj(LIMIT, vector<int>(0,0));
// vector<int> bfs(int start){
//   // discovered[i] = true if ith node is discovered(don't know if visited)
//   vector<bool> discovered(adj.size(), false);
//   // current waiting queue for unvisited nodes
//   queue<int> Q;
//   // node order to visit
//   vector<int> order;
//   discovered[start] = true;
//   Q.push(start);

//   while(!Q.empty()){
//     int here = Q.front();
//     Q.pop();
//     order.push_back(here);
//     for(int i = 0; i < adj[here].size(); i++){
//       int there = adj[here][i];
//       if(!discovered[there]){
//         // discover there & added it to queue
//         Q.push(there);
//         discovered[there] = true;
//       }
//     }
//   }
//   return order;
// }

