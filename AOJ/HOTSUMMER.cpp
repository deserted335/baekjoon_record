#include <iostream>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int tar, Tot = 0;
    cin >> tar;
    for(int i = 0; i < 9; i++){
     int tmp;
     cin >> tmp;
     Tot += tmp; 
    }
    cout << ((Tot <= tar)? "YES" : "NO") << '\n';
  }
}