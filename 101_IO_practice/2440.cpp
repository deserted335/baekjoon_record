#include <iostream>
using namespace std;

int main(){
  int N;
  cin >> N;
  do{
    for(int i = 0; i < N; i++) printf("*");
    printf("\n");
  } while(N--);
}