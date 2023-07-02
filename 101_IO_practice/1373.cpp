#include <iostream>
#include <stack>
using namespace std;
stack<int> S;

int main(){
  string tar;
  long long N = 0, mult = 1;
  cin >> tar;
  int car = tar.length() % 3, t = tar.length() / 3, tmp;

  for(int i = t-1; i >= 0; i--){
    tmp = 4 * (tar[car + 3*i] - '0') + 2 * (tar[car + 1 + 3*i] - '0') + (tar[car + 2 + 3*i] - '0'); 
    S.push(tmp);
  }

  if(car == 2) S.push(2*(tar[0] - '0') + (tar[1] - '0'));
  if(car == 1) S.push(tar[0] - '0');

  while(!S.empty()){
    cout << S.top();
    S.pop();
  }
  
}