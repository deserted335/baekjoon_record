#include <iostream>
#include <math.h>
using namespace std;

int is_prime(int tmp){
  if(tmp == 1) return 0;
  for(int _i = 2; _i <= sqrt(tmp); _i++) if(tmp % _i == 0) return 0;
  return 1;
}

int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int M, N;
  cin >> M >> N;
  for(int i = M; i <= N; i++) if(is_prime(i)) cout << i << '\n';
}