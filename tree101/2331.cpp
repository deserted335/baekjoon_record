#include <iostream>
using namespace std;
int DigitMult[10];
int S[100];

int main(){
  int A, P;
  cin >> A >> P;

  for(int i = 0; i < 10; i++){
    int tmp = 1;
    for(int mul = 0; mul < P; mul++) tmp *= i;
    DigitMult[i] = tmp;
  }
  int tmp = A, pro = 0, N = 100;
  for(int i = 1; i <= 100; i++){
    int flag = 0;
    pro = 0;
    for(char n : to_string(tmp)) pro += DigitMult[n - '0'];
    S[i - 1] = tmp;
    S[i] = pro;
    tmp = pro;
    for(int ind = 0; ind < i; ind++){
      if(pro == S[ind]) {
        cout << ind;
        flag = 1;
        break;
      }
    }
    if (flag) break;
  }
}