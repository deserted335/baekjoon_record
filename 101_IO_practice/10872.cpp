#include <iostream>
using namespace std;

int main(){
  int N;
  cin >> N;
  int tmp = 1;
  while(N) tmp *= N--;
  cout << tmp;
}