#include <iostream>
#include <algorithm>
#define LIMIT 100000
using namespace std;
long A[LIMIT] = {0};

int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int N, ind = 0, cnt = 0, max_cnt = -1; 
  long tmp = A[0], max_val;
  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];
  sort(A, A + N);
  for(ind = 0; ind < N; ind++){
    if(tmp != A[ind]) {
      tmp = A[ind];
      cnt = 1;
    }
    else cnt++;

    if(max_cnt < cnt){
      max_val = A[ind];
      max_cnt = cnt;
    }
  }
  cout << max_val;
}