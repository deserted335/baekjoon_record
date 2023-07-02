#include <iostream>
using namespace std;

int main(){
  char c;
  while((c = getchar()) != '\n'){
    if(c >= 'A' && c <= 'Z') cout << char((c + 13 - 'A') % 26 + 'A');
    else if ( c >= 'a' && c <= 'z') cout << char((c + 13 - 'a') % 26 + 'a');
    else cout << c; 
  }
}