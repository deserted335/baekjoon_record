#include <iostream>
#include <algorithm>
using namespace std;
int dp[10000] = {0};
int glass[10000] = {0};

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> glass[i]; 
  dp[0] = glass[0];
  dp[1] = glass[0] + glass[1];
  dp[2] = max({dp[0] + glass[2], dp[1], glass[2] + glass[1]});
  for(int i = 3; i < n; i++) dp[i] = max({dp[i-1], dp[i-2] + glass[i], dp[i-3] + glass[i] + glass[i-1]});
  cout << dp[n-1] << endl;
}