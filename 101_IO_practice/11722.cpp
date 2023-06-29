#include <iostream>
using namespace std;
int A[1000] = {0};
int dp[1000] = {0};
int seq_cnt[1000] = {0};
// dp[i] : i번째 까지 subseq의 최대 길이
// seq_cnt[i] : A[i]를 끝으로 하는 subseq의 최대 길이
// i = 0:n-1 까지 돌면서 A[i]를 끝으로 하는 최대 길이 subseq를 확인하고, 
// seq_cnt[i] 와 dp[i-1] > ... > dp[0] 와 비교해서 큰 값을 dp[i]로 갱신한다.

int main(){
  int n, tmp;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> A[i];
  // subseq is only 0th num
  dp[0] = 1;
  seq_cnt[0] = 1;
  // if subseq {A[0], A[1]} exists, dp[1] = seq_cnt[1] = 2 > dp[0] = 1 is clear. 
  dp[1] = A[1] < A[0] ? seq_cnt[0] + 1: dp[0];
  seq_cnt[1] = (A[1] < A[0]) ? dp[0] + 1: 1;
  for (int i = 2; i < n; i++) {
    // dummy variable for finding max seq_cnt[j] for j < i which A[i] can be in such subseq
    tmp = 0;
    for (int j = 0; j < i; j++) if (A[j] > A[i] && tmp < seq_cnt[j]) tmp = seq_cnt[j];
    // after loop, tmp is previous subseq length, append A[i]. (length = tmp + 1)
    seq_cnt[i] = tmp + 1;
    dp[i] = max(seq_cnt[i], dp[i-1]);
  }
  cout << dp[n-1];
}