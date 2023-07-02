#include <iostream>
#define LIMIT 100
using namespace std;
int nums[LIMIT];


int this_gcd(int a, int b) {
  return b ? this_gcd(b, a % b) : a; 
}

int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int t, n;
  cin >> t;
  for(int _i = 0; _i < t; _i++){
    cin >> n; 
    long long sum = 0;
    for(int i = 0; i < n; i++) cin >> nums[i];
    for(int i = 0; i < n - 1; i++){
      for(int j = i+1; j < n; j++){
        sum += this_gcd(nums[i], nums[j]); 
      }
    }
    cout << sum << '\n';
  }
}