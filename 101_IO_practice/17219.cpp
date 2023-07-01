#include <iostream>
#include <cstring>
#include <algorithm>
#define LIMIT 100000 
#define STR_LIMIT 20
using namespace std;
char A[LIMIT][2][STR_LIMIT + 1];

int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int N, M;
  char tmp[STR_LIMIT + 1];
  char* tar[2][STR_LIMIT + 1];
  cin >> N >> M;
  for(int i = 0; i < N; i++){
    cin >> A[i][0] >> A[i][1];
  }
  while(M--){
    cin >> tmp;

    cout << '\n';
  }
}