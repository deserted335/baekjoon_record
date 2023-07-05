#include <iostream>
#include <algorithm>
#define LIMIT 1000
using namespace std;
int A[LIMIT];

int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int N, sum = 0;
  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];
  sort(A, A + N);
  for(int i = 0; i < N; i++)
    for (int j = 0; j <= i; j++)
      sum += A[j];
  cout << sum;
}