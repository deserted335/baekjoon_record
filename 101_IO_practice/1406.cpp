#include <iostream>
#include <stack>
using namespace std;
stack<char> S1, S2;

// should use stack or linkedlist
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int M, i = 0;
  char t, inst;
  string tar;
  cin >> tar >> M;
  while(tar[i]) S1.push(tar[i++]);
  for(int k = 0; k < M; k++){
    cin >> inst;
    if(inst == 'L'){
      if(!S1.empty()) {
        S2.push(S1.top());
        S1.pop();
      }
    }
    else if(inst == 'D'){
      if(!S2.empty()) {
        S1.push(S2.top());
        S2.pop();
      }
    }
    else if(inst == 'B'){
      if(!S1.empty()) S1.pop(); 
    }
    else if(inst == 'P'){
      cin >> t;
      S1.push(t);
    }
  }

  while(!S1.empty()){
    S2.push(S1.top());
    S1.pop();
  }

  while(!S2.empty()){
    cout << S2.top();
    S2.pop();
  }
}