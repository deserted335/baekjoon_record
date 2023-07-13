#include <iostream>
#include <string>
#define LIMIT 100000
using namespace std;
string Monsters[LIMIT + 1];

bool isInteger(string tmp){
  if(tmp[0] <= '0' || tmp[0] > '9') 
    return false;
  for(int idx = 1; idx < tmp.size(); idx++) 
    if(tmp[idx] < '0' || tmp[idx] > '9') 
      return false;
  return true;
}

int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  // N : # of monsters, M : # of problems
  int N, M;
  cin >> N >> M;
  for(int i = 1; i <= N; i++) cin >> Monsters[i];
  while(M--){
    string tmp;
    cin >> tmp;
    if(isInteger(tmp)) cout << Monsters[stoi(tmp)] << '\n';
    else{
      for(int idx = 1; idx <= N; idx++){
        if(tmp == Monsters[idx]) {
          cout << idx << '\n';
          break;
        }
      }
    }
  }
}