#include <iostream>
#include <stack>
using namespace std;
stack<int> sizeCheck;

int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int cnt = 0, A, T, tar;
  cin >> A >> T >> tar;

  int BBUNs = 2;
  while(true){
    int flag = 0;
    for (int i = 0; i < 2; i++){
      for (int j = 0; j < 2; j++){
        sizeCheck.push(j);
        if (tar == j){
          cnt++;
          if (cnt == T){
            flag = 1;
            break;
          }
        }
      }
      if(flag) break;
    }
    if(flag) break;
    for(int i = 0; i < BBUNs; i++){
      sizeCheck.push(0);
      if(tar == 0) cnt++;

      if(cnt == T){
        flag = 1;
        break;
      }
    }
    if(flag) break;
    for(int i = 0; i < BBUNs; i++){
      sizeCheck.push(1);
      if(tar == 1) cnt++;

      if(cnt == T){
        flag = 1;
        break;
      }
    }
    if(flag) break;
    BBUNs++;
  }
  cout << (sizeCheck.size() - 1) % A;
}