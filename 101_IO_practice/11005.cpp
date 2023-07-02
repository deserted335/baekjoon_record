#include <iostream>
using namespace std;
int carry[100];
char digits[36 + 1] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
  int N, B, tmp, i = 0;
  cin >> N >> B;
  tmp = N;
  while(tmp >= B){
    carry[i++] = tmp % B;
    tmp /= B;
  }
  carry[i] = tmp;

  for(;i >= 0; i--) cout << digits[carry[i]];
}