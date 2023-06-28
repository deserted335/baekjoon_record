#include <iostream>
using namespace std;
int first_digit_cnt[10] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1};

int main(){
  // is it dp??
  int N, sum = 0;
  int tmp[10] = {0};
  cin >> N;
  for(int i = 2; i <= N; i++){ // i : digit
    for(int i = 0; i < 10; i++) tmp[i] = first_digit_cnt[i];
    first_digit_cnt[0] = tmp[1];
    for(int j = 1; j < 9; j++) first_digit_cnt[j] = (tmp[j-1] + tmp[j+1])%1000000000;
    first_digit_cnt[9] = tmp[8];
  }
  for(int i = 0; i < 10; i++) sum = (sum + first_digit_cnt[i])%1000000000;
  cout << sum;
}