#include <iostream>
#define LIMIT 100000
using namespace std;
unsigned long Sum[LIMIT];

int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  // N : # of nums, M : # of Query
  int N, M;
  unsigned long tmp = 0;
  cin >> N >> M;
  for(int i = 0; i < N; i++){
    unsigned long Cur_Num;
    cin >> Cur_Num;
    tmp += Cur_Num;
    Sum[i] = tmp;
  }

  while(M--){
    int from, to;
    cin >> from >> to;
    from--, to--; // 0-indexify
    unsigned long ret = Sum[to] - Sum[from - 1];
    cout << ret << '\n';
  }
}