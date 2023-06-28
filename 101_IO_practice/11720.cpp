#include <iostream>
using namespace std;

int main(){
  int N, s = 0;
  string tmp; 
  cin >> N >> tmp;
  for(int i = 0; i < N; i++) s += tmp[i] - '0';
  cout << s;
}