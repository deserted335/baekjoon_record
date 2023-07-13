#include <iostream>
#include <string>
using namespace std;
typedef unsigned long long ull;
ull S = 0;


int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  while(t--){
    string inst;
    int val;
    cin >> inst;
    if(inst == "add"){
      cin >> val;
      S |= (1 << val);
    }
    else if(inst == "remove"){
      cin >> val;
      S &= ~(1 << val);
    }
    else if(inst == "check"){
      cin >> val;
      cout << ((S & (1 << val)) != 0) << '\n';
    }
    else if(inst == "toggle"){
      cin >> val;
      S ^= (1 << val); 
    }
    else if(inst == "all"){
      S = -1;
    }
    else if(inst == "empty"){
      S = 0;
    }
  }
}