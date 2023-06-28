#include <iostream>
using namespace std;

int main(){
  int a, b;
  // even if input == NULL, cin returns True. Not good
  while(cin >> a >> b){
    cout << a+b << endl;
  }
}