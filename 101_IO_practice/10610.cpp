#include <iostream>
#include <string>
using namespace std;
string Num;

int main(){
  int DigitSum = 0, c;
  cin >> Num;
  for(char i : Num) DigitSum += i - '0';

  if((c = Num.find('0')) != -1) {
    Num.erase(c);
    Num.append("0");
  }
  cout << ((c != -1) && (DigitSum % 3 == 0) ? Num : "-1");
}