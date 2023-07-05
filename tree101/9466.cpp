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

