#include <iostream>
using namespace std;
string num[4];

int main(){
  string tmp;
  cin >> num[0] >> num[1] >> num[2] >> num[3];
  cout << stoll(num[0] + num[1]) + stoll(num[2] + num[3]);
}