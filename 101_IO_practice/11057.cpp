#include <iostream>
using namespace std;

int main(){
  // dp[lengh][value of Most Significant digit] = # of such ormak num
  int dp[1001][10] = {0};
  int N, sum = 0;
  cin >> N; 
  for(int i = 0; i < 10; i++) dp[1][i] = 1;
  for(int i = 2; i <= N; i++)
    for(int dg = 0; dg < 10; dg++)
      for(int j = dg; j < 10; j++)
        dp[i][dg] = (dp[i][dg] + dp[i-1][j])%10007;
  for(int i = 0; i < 10; i++) sum = (sum + dp[N][i]) % 10007;
  cout << sum;
}