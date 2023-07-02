#include <iostream>
#include <queue>
using namespace std;
queue<int> S;
string E;
char out_str[8][4] = {"000", "001", "010", "011", "100", "101", "110", "111"};
char first_out[8][4] = {"", "1", "10", "11", "100", "101", "110", "111"};

int main(){
  cin >> E;
  if(E == "0"){
    cout << 0;
    return 0;
  }
  for(int i = 0; i < E.length(); i++) S.push(E[i] - '0');
  cout << first_out[S.front()];
  S.pop();
  while(!S.empty()){
    cout << out_str[S.front()];
    S.pop();
  }
}