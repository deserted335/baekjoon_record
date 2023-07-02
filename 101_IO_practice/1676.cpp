#include <iostream>
#include <string>
using namespace std;

int main(){
  int N, cnt = 0;
  cin >> N;
  while(N / 5 != 0){
    cnt += N / 5;
    N /= 5;
  } 
  cout << cnt;
}