#include <iostream>
using namespace std;

int main(){
  char dir[5] = "NESW"; 
  int sum = 0, tmp;
  for(int i = 0; i < 10; i++){
    cin >> tmp;
    sum = (sum + tmp) % 4;
  }
  cout << dir[sum] ;
}