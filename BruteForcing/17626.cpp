#include <iostream>
#include <cmath>
#define INF 987654321
#define LIMIT 50000
using namespace std;
int DP[LIMIT + 1] = {0};

int MinSquares(int tar){
  // base case : itself is square number or 0
  int SqrtTar = sqrt(tar);
  if(tar <= 0) return 0;
  if(tar == SqrtTar * SqrtTar) return DP[tar] = 1;
  if(DP[tar] != 0) return DP[tar];

  int CntMin = INF;
  for(int Test = SqrtTar; Test >= SqrtTar / 2; Test--){
    int NextTar = tar - Test * Test;
    CntMin = min(CntMin, 1 + MinSquares(NextTar));
  }
  return DP[tar] = CntMin;
}

int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  // corner case : MinSquares does not hold (SqrtTar / 2 == 0)
  DP[2] = 2;
  DP[3] = 3;

  // target integer n <= 50000
  int n;
  cin >> n;
  cout << MinSquares(n);
}