#include <iostream>
#include <algorithm>
#define LIMIT 100000
using namespace std;
string Type[LIMIT];

int cmp(int i, int j){
  int ret = 0;
  for(int _i = 0; _i < 4; _i++){
    if(Type[i][_i] != Type[j][_i]) ret += 1;
  }
  return ret;
}

int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int T, N, d;
  cin >> T;
  for(int _i = 0; _i < T; _i++){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> Type[i];
    int tmp = 12 + 1;
    sort(Type, Type + N);
    for(int i = 0; i < N-2; i++){
      for(int j = i+1; j < N-1; j++){
        for(int k = j+1; k < N; k++){
          d = cmp(i, j) + cmp(j, k) + cmp(i, k);
          if(tmp > d) tmp = d;
        }
      }
    }
    cout << tmp << "\n";
  }
}