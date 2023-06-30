#include <iostream>
using namespace std;
int DP[201][201] = {0};

int main(){
  int N, K;
  cin >> N >> K;

  for(int i = 0; i <= N; i++) DP[1][i] = 1;

  // DP(N, K) = sum_i DP(i, K-1) where DP(i, 1) = 1 
  for(int i = 2; i <= K; i++){
    for(int ind = 0; ind <= N; ind++){
      for(int j = 0; j <= ind; j++) DP[i][ind] = (DP[i][ind] + DP[i-1][j])%1000000000; 
    }
  }
  cout << DP[K][N];

}