#include <iostream>
using namespace std;

int main(){
  long long N = 0;
  int B, mult = 1, tmp;
  string tar;
  cin >> tar >> B;
  for(int i = tar.length() - 1; i >= 0; i--){
    if(tar[i] >= '0' && tar[i] <= '9') tmp = tar[i] - '0';
    else tmp = tar[i] - 'A' + 10;
    N += tmp * mult;
    mult *= B; 
  }
  cout << N;
}