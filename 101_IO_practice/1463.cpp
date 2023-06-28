#include <iostream>
using namespace std;

int cache[1000001] = {0};


int main(){
  int N, tmp;
  cin >> N;
  for(int i = 2; i < N + 1; i++){
    cache[i] = cache[i-1] + 1;
    if(i%3 == 0) cache[i] = cache[i] < (tmp = cache[i/3] + 1)? cache[i] : tmp;
    if(i%2 == 0) cache[i] = cache[i] < (tmp = cache[i/2] + 1)? cache[i] : tmp;
  }
  cout << cache[N];
}