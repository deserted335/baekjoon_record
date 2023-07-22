#include <iostream>
#include <vector>
#include <string>
using namespace std;
int adj_mat[26][26] = {0};
int tar[26];

int charLen(char* tar){
  int len = 0;
  while(tar[++len]);
  return len;
}

int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int Cases, Words;
  char pre[21], pro[21];

  cin >> Cases;
  for(int _i = 0; _i < Cases; _i++){
    int isInvalid = 0;
    for(int i = 0; i < 26; i++) {
      fill_n(adj_mat[i], 26, 0);
      tar[i] = i;
    }
    cin >> Words;
    cin >> pre;
    for(int i = 1; i < Words; i++){
      cin >> pro;
      for(int j = 0; j < min(charLen(pre), charLen(pro)); j++){
        int from = pre[j] - 'a', to = pro[j] - 'a';
        if(from != to){
          if(adj_mat[to][from] == 1) {
            isInvalid = 1;
            break;}
          adj_mat[from][to] = 1;
          // swap different char 
          int tmp;
          tmp = tar[to];
          tar[to] = tar[from];
          tar[from] = tmp;
        }
        for(int j = 0; j <= charLen(pro); j++) pre[j] = pro[j];
      }
    }
    if (isInvalid == 1)
      cout << "INVALID HYPOSHESIS";
    else
      for(int i = 0; i < 26; i++) cout << char('a' + tar[i]);
    cout << '\n';
  }
}