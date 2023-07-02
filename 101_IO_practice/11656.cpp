#include <iostream>
#include <algorithm>
#define LIMIT 1000
using namespace std;
string tmp[LIMIT];

int main(){
  string tar;
  cin >> tar;
  int len = tar.length();
  for(int i = 0; i < len; i++) tmp[i] = tar.substr(i);
  sort(tmp, tmp + len);
  for(int i = 0; i < len; i++) cout << tmp[i] << '\n';
}