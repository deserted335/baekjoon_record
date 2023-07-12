#include <iostream>
#include <string>
using namespace std;

int IntContainsK(int tar, int K){
  int tens = tar / 10, zeros = tar % 10;
  return (tens == K) || (zeros == K);
}

int isContained(int time, int K){
  // return 1 if time(sec) : HHMMSS has K / 0 otherwise
  int H, M, S;
  S = time % 60;
  M = (time / 60) % 60;
  H = time / 3600;
  return IntContainsK(S, K) || IntContainsK(M, K) || IntContainsK(H, K);
}

int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int N, K, cnt = 0;
  cin >> N >> K;

  for(int t = 0; t < (N + 1) * 3600; t++) cnt += isContained(t, K);
  cout << cnt;
}