#include <iostream>
using namespace std;

int main(){
  int C, BitConv[4][8];
  cin >> C;
  while(C--){
    long long tar;
    cin >> tar;
    for(int dig = 0; dig < 4; dig++){
      for(int bit = 0; bit < 8; bit++){
        BitConv[dig][bit] = tar % 2;
        tar /= 2;
      }
    }
    long long ret = 0, mult = 1;
    for(int dig = 3; dig >= 0; dig--){
      for(int bit = 0; bit < 8; bit++){
        long long tmp = BitConv[dig][bit] * mult;
        ret += tmp;
        mult *= 2;
      }
    }
    cout << ret << '\n';
  }
}