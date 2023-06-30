#include <iostream>
using namespace std;
int DP[5001] = {0};
char tar[5000];

int main()
{
  int len = 0, tmp;
  // DP[i] : possible # of decodes of 0 : i+1 string
  // DP[i] += DP[i-1] : DP[i-1] if tar[i] is valid (tar[i] != 0)/
  // DP[i] += DP[i-2] :  DP[i-2] if digit{DP[i-1], DP[i]} is valid (10<= # <=26)
  cin >> tar;

  while (tar[len++]) continue;
  if(tar[0] == '0'){
    cout << 0;
    return 0;
  }
  DP[0] = 1; // DP[2] corner case
  DP[1] = 1;


  for (int i = 2; i < len; i++)
  {
    if (tar[i-1] != '0'){
      DP[i] = (DP[i] + DP[i-1])%1000000;
    }
    if (tar[i-2] == '1' || tar[i-2] == '2' && tar[i-1] <= '6'){
      DP[i] = (DP[i] + DP[i-2])%1000000;
    }
  }
  cout << DP[len-1] % 1000000;
}