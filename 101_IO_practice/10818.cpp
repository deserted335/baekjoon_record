#include <iostream>
using namespace std;

int main(){
  int mx = -1000000, mn = 1000000;
  int N, tmp;
  cin >> N;
  while(N--){
    cin >> tmp;
    if(tmp > mx) mx = tmp;
    if(mn > tmp) mn = tmp;
  }
  printf("%d %d", mn, mx);
}