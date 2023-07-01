#include <iostream>
#define LIMIT 10000 
using namespace std;
int A[LIMIT] = {0};

int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int N, tmp;
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> tmp;
    A[tmp-1] += 1; 
  }

  for(int i = 0; i < LIMIT; i++)
    for(int j = 0; j < A[i]; j++)
      cout << i + 1 << '\n';
}