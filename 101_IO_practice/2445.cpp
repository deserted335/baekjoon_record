#include <iostream>
using namespace std;

int main(){
  int N;
  cin >> N;
  for (int i = 0; i < N-1; i++){
    for (int j = 0; j <= i; j++) printf("*");
    for (int j = 0; j < 2*(N-i-1); j++) printf(" ");
    for (int j = 0; j <= i; j++) printf("*");
    printf("\n");
  }
  for (int i = 0; i < 2*N; i++) printf("*");
  printf("\n");
  for (int i = N-2; i >= 0; i--){
    for (int j = 0; j <= i; j++) printf("*");
    for (int j = 0; j < 2*(N-i-1); j++) printf(" ");
    for (int j = 0; j <= i; j++) printf("*");
    printf("\n");
  }
}