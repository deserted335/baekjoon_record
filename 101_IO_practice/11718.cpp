#include <iostream>
using namespace std;

int main(){
  string given;
  while(getline(cin, given)){
    if(given.empty()){break;}
    cout << given << endl;
  }
}
