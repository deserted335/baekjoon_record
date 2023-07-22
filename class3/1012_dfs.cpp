#include <iostream>
#include <vector>
#define LIMIT 50
#define TYPE 4
using namespace std;
const int dx[TYPE] = {1, 0, -1, 0}; 
const int dy[TYPE] = {0, -1, 0, 1}; 
// Cabbage[y][x] : 1 if Cabbage is in (x,y), 0 otherwise
int Cabbage[LIMIT][LIMIT] = {0};
int Width, Height, Cabbages;

void Dfs(const int Cabbage[LIMIT][LIMIT], bool visited[LIMIT][LIMIT], int x, int y){
  // dfs from (x, y)
  for(int type = 0; type < TYPE; type++){
    int Cur_x = x + dx[type], Cur_y = y + dy[type];
    if(Cur_x < 0 || Cur_x > Width - 1 || Cur_y < 0 || Cur_y > Height - 1)
      continue; // out of range
    
    if(Cabbage[Cur_y][Cur_x] && !visited[Cur_x][Cur_y]){
      visited[Cur_x][Cur_y] = true;
      Dfs(Cabbage, visited, Cur_x, Cur_y);
    } 
  }
}

int Dfs_Connected_component(const int Cabbage[LIMIT][LIMIT], bool visited[LIMIT][LIMIT]){
  // connected component of Cabbage.
  int ret = 0;
  for(int y = 0; y < Height; y++){
    for(int x = 0; x < Width; x++){
      if(Cabbage[y][x] && !visited[x][y]){
        ret++;
        Dfs(Cabbage, visited, x, y);
      }
    }
  }
  return ret;
}

int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int testcase;
  cin >> testcase;
  while(testcase--){
    // visited[x][y] : true if visited, false otherwise
    bool visited[LIMIT][LIMIT] = {0};

    cin >> Width >> Height >> Cabbages;

    while(Cabbages--){
      int x, y;
      cin >> x >> y;
      Cabbage[y][x] = 1;
    }

    cout << Dfs_Connected_component(Cabbage, visited) << '\n';

    for(int rm = 0; rm < Height; rm++) fill_n(Cabbage[rm], Width, 0);
  }
}