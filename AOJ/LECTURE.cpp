#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string Pieces[500];

int main(){
  int T;
  cin >> T;
  while(T--){
    string tmp;
    cin >> tmp;
    for(int i = 0; i < tmp.size() / 2; i++) Pieces[i] = tmp.substr(2*i, 2);
    sort(Pieces, Pieces + tmp.size() / 2);
    for(int i = 0; i < tmp.size() / 2; i++) cout << Pieces[i];
    cout << '\n';
  }
}