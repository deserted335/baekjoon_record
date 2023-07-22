#include <iostream>
#include <vector>
#define LIMIT 200 
using namespace std;
bool ImpossibleAdj[LIMIT + 1][LIMIT + 1] = {0};

int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  // N : # of flavors, M : # of impossible pairing
  int N, M; 
  cin >> N >> M;
  for(int pairs = 0; pairs < M; pairs++){
    int from, to;
    cin >> from >> to;
    // 1-index array
    ImpossibleAdj[from][to] = true;
    ImpossibleAdj[to][from] = true;
  }

  long long cnt = 0;
  for(int pair1 = 1; pair1 <= N - 2; pair1++){
    for(int pair2 = pair1 + 1; pair2 <= N - 1; pair2++){
      if(ImpossibleAdj[pair1][pair2]) continue;
      for(int pair3 = pair2 + 1; pair3 <= N; pair3++){
        if(ImpossibleAdj[pair2][pair3] || ImpossibleAdj[pair1][pair3]) continue;
        cnt++;
      }
    }
  }

  cout << cnt;
}