#include <iostream>
using namespace std;
int LIS[1000] = {0};
int LIS_rev[1000] = {0};
int dp[1000] = {0};
int A[1000] = {0};

int main(){
  // LIS , reverse LIS 
  int N, tmp;
  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];

  LIS[0] = 1, LIS[1] = A[1] > A[0]? 2 : 1;
  LIS_rev[N-1] = 1, LIS_rev[N-2] = A[N-2] > A[N-1]? 2 : 1;

  for(int i = 2; i < N; i++){
    tmp = 0;
    for(int j = 0; j < i; j++){
      if(A[j] < A[i] && tmp < LIS[j]) tmp = LIS[j];
    }
    LIS[i] = tmp + 1;

    tmp = 0;
    for(int j = 0; j < i; j++){
      if(A[N- j - 1] < A[N - i - 1] && tmp < LIS_rev[N - j - 1]) tmp = LIS_rev[N - j - 1];
    }
    LIS_rev[N - i - 1] = tmp + 1;

  }

  for(int i = 0; i < N; i++){
    dp[i] = LIS[i] + LIS_rev[i] - 1;
    dp[i] = dp[i] > dp[i-1] ? dp[i] : dp[i-1];
  }

  cout << dp[N-1];
}