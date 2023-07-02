#include <iostream>
using namespace std;

int gcd(int a, int b){
  int t1 = max(a, b);
  int t2 = min(a, b); 
  if(t2 == 0) return t1;
  return gcd(t2, t1 % t2);
}

int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int T, A, B;
  cin >> T;
  for(int i = 0; i < T; i++){
    cin >> A >> B;
    cout << A * B  / gcd(A, B) << '\n';
  }
}