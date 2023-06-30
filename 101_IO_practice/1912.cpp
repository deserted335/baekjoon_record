#include <iostream>
using namespace std;
int A[100000] = {0};
int dp[100000] = {0};
int seq_ends_sum[100000] = {0};


int main(){
  // seq_ends_sum[i] for sum of seq ends with A[i] which is greatest sum
  int n;
  cin >>n;
  for(int i = 0; i < n; i++) cin >> A[i];
  seq_ends_sum[0] = A[0];
  dp[0] = A[0];
  for(int i = 1; i < n; i++){
    seq_ends_sum[i] = seq_ends_sum[i-1] > 0 ? A[i] + seq_ends_sum[i-1] : A[i];
    dp[i] = seq_ends_sum[i] > dp[i-1] ? seq_ends_sum[i] : dp[i-1];
  } 
  cout << dp[n-1];
}