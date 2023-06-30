#include <iostream>
using namespace std;
long long P[100];

int main(){
  int N, T;
  cin >> T;
  P[0] = 1, P[1] = 1, P[2] = 1, P[3] = 2, P[4] = 2;
  for (int i = 5; i < 100; i++)
    P[i] = P[i - 1] + P[i - 5];
  while (T--)
  {
    cin >> N;
    cout << P[N - 1] << endl;
  }
}