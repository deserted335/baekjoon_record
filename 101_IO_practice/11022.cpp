#include <iostream>
using namespace std;

int main(){
  int N, a, b;
  cin >> N;
  for(int i = 1; i <= N; i++){
    cin >> a >> b;
    printf("Case #%d: %d + %d = %d\n", i,a,b, a+b);
    }
  return 0;
}