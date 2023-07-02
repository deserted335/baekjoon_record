#include <iostream>
#include <algorithm>
#include <string>
#define LIMIT 100
using namespace std;
string S;

int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int N, A = 0, a = 0, E = 0, n = 0, tmp;

  while(1){
    getline(cin, S);
    if (!S[0]) break;
    A = 0, a = 0, E = 0, n = 0;
    for(int ind = 0; tmp = S[ind]; ind++){
      if(tmp >= 'A' && tmp <= 'Z') A++;
      else if(tmp >= 'a' && tmp <= 'z') a++;
      else if(tmp >= '0' && tmp <= '9') n++;
      else if(tmp == ' ') E++;
    }
    cout << a << " " << A << " " << n << " " << E << "\n";
    getline(cin, S);
  }
}