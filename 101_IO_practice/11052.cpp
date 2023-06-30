#include <iostream>
using namespace std;
int P[1001] = {0};
int DP[1001] = {0};

int main(){
  // DP[i] : from 1 to ith ind of P, largest sum of i cards.
  // then DP[i] = max(P[i], DP[i-1] + DP[1], DP[i-2] + DP[2], ... , DP[i//2] + DP[i//2-1])
  int N, tmp;
  cin >> N;
  for(int i = 1; i <= N; i++) cin >> P[i];
  DP[1] = P[1];
  for(int i = 2; i <= N; i++){
    tmp = P[i];
    for(int j = 1; j <= i/2; j++) tmp = max(tmp, DP[i-j] + DP[j]);
    DP[i] = tmp;
  }
  cout << DP[N];
}