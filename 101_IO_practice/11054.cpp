#include <iostream>
#include <memory.h>
#include <algorithm>
#define HITORI -1
using namespace std;
int dp[1000] = {0};
int A[1000] = {0};
int seq_cnt[1000][2] = {0};
int is_increasing[1000];
int is_decreasing[1000] = {0};

int main(){
  // 실패...
  memset(is_increasing, HITORI, sizeof(is_increasing));
  memset(is_decreasing, HITORI, sizeof(is_decreasing));
  
  int N, tmp_inc, tmp_dec;
  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];
  seq_cnt[0][0] = 1, seq_cnt[0][1] = 1, dp[0] = 1;
  is_increasing[1] = A[1] > A[0];
  seq_cnt[1][0] = A[1] > A[0] ? 2 : 1, seq_cnt[1][1] = A[0] > A[1] ? 2 : 1;
  dp[1] = 2;
  for(int i = 2; i < N; i++){
    // 증가하는 부분수열과 감소하는 부분수열 둘 다 존재하는지 따져야 한다.
    tmp_inc = 0;
    for(int j = 0; j < i; j++){
      if(is_increasing[j] > 0 && A[j] != A[i] && tmp_inc < seq_cnt[j][0]){
        tmp_inc = seq_cnt[j][0];
        is_increasing[i] = A[i] > A[j];
      }    
      if(is_increasing[j] == 0 && A[j] > A[i] && tmp_inc < seq_cnt[j][0]){
        tmp_inc = seq_cnt[j][0];
        is_increasing[i] = 0;
      }
      if(is_increasing[j] < 0 && A[j] != A[i] && tmp_inc < seq_cnt[j][0]){
        tmp_inc = seq_cnt[j][0];
        is_increasing[i] = A[i] > A[j];
      }
    }
    tmp_dec = 0;
    for(int j = 0; j < i; j++){
      if(is_decreasing[j] > 0 && A[j] != A[i] && tmp_dec < seq_cnt[j][1]){
        tmp_dec = seq_cnt[j][1];
        is_decreasing[i] = A[i] < A[j];
      }    
      if(is_decreasing[j] == 0 && A[j] > A[i] && tmp_dec < seq_cnt[j][1]){
        tmp_dec = seq_cnt[j][1];
        is_decreasing[i] = 0;
      }
      if(is_decreasing[j] < 0 && A[j] != A[i] && tmp_dec < seq_cnt[j][1]){
        tmp_dec = seq_cnt[j][1];
        is_decreasing[i] = A[i] < A[j];
      }
    }
    seq_cnt[i][0] = tmp_inc + 1;
    seq_cnt[i][1] = tmp_dec + 1;
    dp[i] = max(seq_cnt[i][0], seq_cnt[i][1]) > dp[i-1] ? max(seq_cnt[i][0], seq_cnt[i][1]) : dp[i-1];
  }
  cout << "\n" << dp[N-1];
}