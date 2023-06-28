#include <iostream>
using namespace std;

// int main(){
//   string given;
//   for(int i = 0; i < 100; i++){
//   getline(cin, given);
//   cout << given << endl;
//   }
//   return 0;
// }

int main() {
  // hmm...cool but infinite loop
  char c;
  while((c = getchar()) != EOF) cout << c;
}