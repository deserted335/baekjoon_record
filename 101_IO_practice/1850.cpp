#include <iostream>
using namespace std;

long long this_gcd(long long a, long long b){
  if(a*b == 0) return (a == 0)? b : a;
  return (a > b) ? this_gcd(b, a % b) : this_gcd(a, b % a);
}

int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  long long A, B;
  cin >> A >> B;
  for(int i = 0; i < this_gcd(A, B); i++) cout << '1'; 
}