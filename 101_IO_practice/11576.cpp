#include <iostream>
#include <stack>
using namespace std;
stack<int> Digit;

int main(){
  int A, B, m, mult, sum, tmp;

  cin >> A >> B >> m;

  for(int _i = 0; _i < m; _i++){
    cin >> tmp;
    Digit.push(tmp);
  }
  // convert to Base10
    mult = 1, sum = 0;
    while(!Digit.empty()){
      sum += Digit.top() * mult;
      Digit.pop();
      mult *= A;
    }
  // convert to Base B
    mult = 1;
    while(sum != 0){
      Digit.push(sum % B);
      sum /= B;
    }
    while(!Digit.empty()){
      cout << Digit.top() << " ";
      Digit.pop();
    }
}