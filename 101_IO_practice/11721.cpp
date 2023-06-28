#include <iostream>
using namespace std;

int main(){
  int cnt = 0;
  string tmp; 
  cin >> tmp;
  for(int i = 0; i < tmp.length(); i++) {
    if(cnt == 10) {
      cout << endl;    
      cnt = 0;
    }
    cout << tmp[i];
    cnt++;
  }
}