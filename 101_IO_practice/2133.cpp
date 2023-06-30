#include <iostream>
using namespace std;
int dp[31] = {0};

int main(){
  int N;
  cin >> N;
  if(N%2) cout << 0 << endl;
  else{
  dp[2] = 3;
  for(int i = 2; i <= N/2; i++){
    // attach 3*2 pieces to left
    dp[2*i] = dp[2 * i - 2] * 3 + 2;
    // attach 2 special pieces(3*4, 3*6, 3*8, ... , 3*(2i-2)) to left
    for(int j = 2; j < i; j++) dp[2*i] += dp[2*j - 2] * 2;
  }
  cout << dp[N];
  }
}