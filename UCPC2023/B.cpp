#include <iostream>
#define LIMIT 100000
using namespace std;
int pos[LIMIT];
int path[LIMIT / 2][LIMIT / 2] = {0};

int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int N, K, M;
  cin >> N >> K >> M;
  for(int i = 0; i < N; i++) cin >> pos[i];
  for(int i = 0; i < M; i++){
    int from, to, tmp;
    cin >> from >> to >> tmp; 
    path[from][to] = max(tmp, path[from][to]);
  }
// cont

}