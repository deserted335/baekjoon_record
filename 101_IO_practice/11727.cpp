#include <iostream>
using namespace std;
int dp[1001] = {0};

int main(){
  // altered fibonacci seq. left is 2*1 (dp[i-1]) or two 1*2 or 2*2 (both dp[i-2]) 
  int N;
  cin >> N;
  dp[1] = 1;
  dp[2] = 3;
  for(int i = 3; i <= N; i++) dp[i] = (dp[i-1] + 2*dp[i-2])%10007;
  cout << dp[N];
}