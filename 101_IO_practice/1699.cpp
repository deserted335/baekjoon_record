#include <iostream>
using namespace std;
int dp[100001] = {0};
int squares[1001] = {0};

int main()
{
  int N, end, tmp;
  cin >> N;
  for (int i = 0; i < 1000; i++)
  {
    // pre-calculate squares
    squares[i] = i * i;
  }
  dp[0] = 0;
  for (int j = 1; j <= N; j++)
  {
      // find largest square which is smaller than j
    for (int ind = 0; ind < 1001; ind++)
    {
      if (squares[ind] <= j)
        end = ind;
      else
        break;
    }
    tmp = 100000;
    for (int i = end; i > 0; i--)
        // from largest square ~~ to 1, find minimum split
      tmp = min(tmp, dp[j - squares[i]] + 1);
    dp[j] = tmp;
      // do it j = 1 to N
  }
  cout << dp[N];
}