#include <iostream>
using namespace std;

int main(){
  int N;
  cin >> N;
  N++; 
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N - i - 1; j++) printf(" ");
    for (int j = 0; j < i; j++) printf("* ");
    printf("\n");
  }
}