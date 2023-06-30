#include <string.h>
#include <iostream>
#define mod 1000000
using namespace std;
 
int DP[5000] = {0};
char tar[5000];
 
int main(void)
{
  // reference by https://data-make.tistory.com/430
    int i, len = 0;
    cin >> tar;
    
    if (tar[0] == '0') {
        cout << 0;
        return 0;
    }
    
    DP[0] = 1;
    for (i = 1; i < strlen(tar); i++) {
        if(tar[i] != '0')
            DP[i] += DP[i - 1] % mod;
        
        if (tar[i - 1] == '1' || tar[i - 1] == '2' && tar[i] <= '6')
            DP[i] += i > 1 ? DP[i - 2] % mod : 1;
    }
 
    cout << DP[strlen(tar) - 1] % mod;
 
    return 0;
}
