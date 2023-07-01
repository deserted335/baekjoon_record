#include <iostream>
using namespace std;
int DP[41][2];

int main(){
  int T, tmp;
  cin >> T;
  DP[0][0] = 1, DP[0][1] = 0;
  DP[1][0] = 0, DP[1][1] = 1;
  DP[2][0] = 1, DP[2][1] = 1;
  for(int i = 3; i <= 40; i++){
    DP[i][0] = DP[i - 1][0] + DP[i - 2][0];
    DP[i][1] = DP[i - 1][1] + DP[i - 2][1];
  }
  while(T--) {
    cin >> tmp;
    cout << DP[tmp][0] << " " << DP[tmp][1] << "\n";
  }
}