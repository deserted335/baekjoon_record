#include <iostream>
#include <memory.h>
using namespace std;
int dp[2][100000] = {0};
int stickers[2][100000] = {0};

int main(){
  int T, n, s, tmp;
  cin >> T;
  while(T--){
    cin >> n;
    s = 0;
    memset(stickers, 0, sizeof(stickers));
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; i++) cin >> stickers[0][i];
    for(int i = 0; i < n; i++) cin >> stickers[1][i];

    dp[0][0] = stickers[0][0];
    dp[1][0] = stickers[1][0];
    dp[0][1] = dp[1][0] + stickers[0][1];
    dp[1][1] = dp[0][0] + stickers[1][1];

    for(int i = 2; i < n; i++){
      dp[0][i] = max(dp[1][i-1], dp[1][i-2]) + stickers[0][i];
      dp[1][i] = max(dp[0][i-1], dp[0][i-2]) + stickers[1][i];
    }

    cout << max(dp[0][n-1], dp[1][n-1]) << endl;
  }
}