#include <iostream>
#define STR_LIMIT 50
using namespace std;
char A[STR_LIMIT + 1];
int tmp[STR_LIMIT];

int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int N, ind, flag;
  char c;
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> A;
    fill_n(tmp, STR_LIMIT, -1);
    ind = 0;
    flag = 0;
    for(int j = 0; c = A[j]; j++){
      if(c == '(')  tmp[ind++] = 0;
      else{
        if(ind > 0) tmp[--ind] = -1;
        else{
          flag = 1;
          break;
        }
      }
    }
    if(tmp[0] == -1 && !flag) cout << "YES" << '\n';
    else cout << "NO" << '\n';
  }
}