#include <iostream>
using namespace std;
long long dp[91] = {0};

int main(){
  // case : 10 + (i-2)pinary num / 100 + (i-3)pinary num / 1000 + (i-4)pinary num + ... + 1000...
  // why is this pibonacci???
  int N;
  cin >> N;
  dp[1] = 1;
  dp[2] = 1;
  for(int i = 3; i <= N; i++){ 
    dp[i] = 1;
    for(int j = i-2; j >= 1; j--) dp[i] += dp[j];
  }
  cout << dp[N];
}