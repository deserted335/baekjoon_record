#include <iostream>
using namespace std;
int dp[11] = {0};

int main(){
  // case : first adder is 1(dp[i-1]), 2(dp[i-2]), 3(dp[i-3])
  int T, N;
  cin >> T;
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;
  for(int i = 4; i <= 10; i++) dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
  while(T--){
    cin >> N;
    cout << dp[N] <<endl;
  }
}
