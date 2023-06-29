#include <iostream>
#include <algorithm>
using namespace std;
int A[1000] = {0};
int dp[1000] = {0};
int sub_sum[1000] = {0};
// dp[i] : i��° ���� subseq�� �ִ� ��
// sub_sum[i] : A[i]�� ������ �ϴ� subsequence���� ���� �ִ�
// i = 0:n-1 ���� ���鼭 A[i]�� ������ �ϴ� �ִ� ���� subseq�� Ȯ���ϰ�, 
// sub_sum[i] �� dp[i-1] > ... > dp[0] �� ���ؼ� ū ���� dp[i]�� �����Ѵ�.

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