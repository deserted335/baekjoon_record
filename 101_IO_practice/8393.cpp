#include <iostream>
using namespace std;

int main(){
  int N, s = 0;
  cin >> N;
  for(int i = 1; i <= N; i++) s += i;
  cout << s;
}