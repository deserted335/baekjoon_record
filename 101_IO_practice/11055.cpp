#include <iostream>
#include <algorithm>
using namespace std;
int A[1000] = {0};
int dp[1000] = {0};
int sub_sum[1000] = {0};
// dp[i] : i번째 까지 subseq의 최대 합
// sub_sum[i] : A[i]를 끝으로 하는 subsequence들의 합의 최대
// i = 0:n-1 까지 돌면서 A[i]를 끝으로 하는 최대 길이 subseq를 확인하고, 
// sub_sum[i] 와 dp[i-1] > ... > dp[0] 와 비교해서 큰 값을 dp[i]로 갱신한다.

int main(){
  int n, tmp;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> A[i];
  // subseq is only 0th num
  dp[0] = A[0];
  sub_sum[0] = A[0];
  // if subseq {A[0], A[1]} exists, dp[1] = sub_sum[1] = A[0] + A[1] > dp[0] = A[0] is clear. 
  dp[1] = A[1] > A[0] ? sub_sum[0] + A[1]: dp[0];
  sub_sum[1] = (A[1] > A[0]) ? dp[0] + A[1]: A[1];
  for (int i = 2; i < n; i++) {
    // dummy variable for finding max seq_cnt[j] for j < i which A[i] can be in such subseq
    tmp = 0;
    for (int j = 0; j < i; j++) if (A[j] < A[i] && tmp < sub_sum[j]) tmp = sub_sum[j];
    // after loop, tmp is previous subseq sum, append A[i]. (sum = tmp + 1)
    sub_sum[i] = tmp + A[i];
    dp[i] = max(sub_sum[i], dp[i-1]);
  }
  cout << dp[n-1];
}