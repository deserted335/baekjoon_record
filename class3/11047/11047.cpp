#include <iostream>
#define LIMIT 10 
using namespace std;
int Coins[LIMIT];

int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int N, K;
  cin >> N >> K;
  for (int i = 0; i < N; i++) cin >> Coins[i];
  int cnt = 0;
  for(int i = N-1; i >= 0; i--){
    cnt += K / Coins[i];
    K %= Coins[i];
  }
  cout << cnt;
}