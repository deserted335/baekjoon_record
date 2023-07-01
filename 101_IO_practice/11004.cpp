#include <iostream>
#include <algorithm>
#define LIMIT 5000000
using namespace std;
int A[LIMIT];

int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int N, K;
  cin >> N >> K;
  for(int i = 0; i < N; i++) cin >> A[i];
  sort(A, A + N);
  cout << A[K-1];
}