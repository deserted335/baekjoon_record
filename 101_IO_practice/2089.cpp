#include <iostream>
#include <stack>
using namespace std;
stack<int> dig;


int main(){
  int N, B = -2, r;
  cin >> N;
  if(N == 0) cout << 0;
  while(N != 0){
    r = (N % B < 0) ? N % B - B : N % B;
    dig.push(r);
    N = (N - r) / B;
  }
  while(!dig.empty()){
    cout << dig.top();
    dig.pop();
  }
}