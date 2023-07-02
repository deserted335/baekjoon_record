#include <iostream>
#include <math.h>
#define LIMIT 1000000
using namespace std;
int is_P[LIMIT + 1];

int is_prime(int tmp){
  if(is_P[tmp] != -1) return is_P[tmp];
  for(int _i = 2; _i <= sqrt(tmp); _i++) 
    if(tmp % _i == 0) return is_P[tmp] = 0;
  return is_P[tmp] = 1;
}

int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int tmp;
  fill_n(is_P, LIMIT + 1, -1);
  is_P[1] = 0; 
  for(int i = 2; i < LIMIT + 1; i += 2) is_P[i] = 0;
  // if pre-calculate is_P, can reduce time 

  while(1){
    cin >> tmp;
    if(tmp == 0) break;
    // ¦ = Ȧ + Ȧ
    for (int i = 3; i <= tmp / 2; i += 2)
      if (is_prime(i) && is_prime(tmp - i)){
        cout << tmp << " = " << i << " + " << tmp - i << '\n';
        break;
      }
  }
}