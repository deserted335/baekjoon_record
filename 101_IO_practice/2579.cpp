#include <iostream>
using namespace std;

int A[300] = {0};
int dp[300] = {0};
int seq_sum[300] = {0};

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> A[i];
  seq_sum[0] = A[0];
  seq_sum[1] = A[0] + A[1];
  // 시작점은 계단에 포함되지 않는다...A[1]+A[2]도 가능함
  seq_sum[2] = max(A[0] + A[2], A[1] + A[2]);
  for(int i = 3; i < n; i++) seq_sum[i] = max(seq_sum[i-2] + A[i], seq_sum[i-3] + A[i-1] + A[i]);
  cout << seq_sum[n-1] << endl;
}