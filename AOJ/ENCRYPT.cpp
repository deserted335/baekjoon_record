#include <iostream>
using namespace std;

int main(){
  int T;
  cin >> T;
  while(T--){
    string tar;
    cin >> tar;
    for(int i = 0; i < tar.length(); i += 2) cout << tar[i];
    for(int i = 1; i < tar.length(); i += 2) cout << tar[i];
    cout << '\n';
  }
}