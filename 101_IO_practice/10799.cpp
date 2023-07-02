#include <iostream>
#define STR_LIMIT 100000
using namespace std;
int tmp[STR_LIMIT];
char A[STR_LIMIT + 1] = {0};

int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int ind = 0, sum = 0;
  char c1, c2;
  cin >> A;
  for (int j = 0; (c1 = A[j]); j++) {
    c2 = A[j+1];
    if (c1 == '(' && c2 != ')') tmp[ind++] = 1;
    else if(c1 == '(' && c2 == ')') {
      for(int k = 0; k < ind; k++) tmp[k] += 1;
      j++; // skip ()
    } 
    else {
      sum += tmp[ind - 1];
      tmp[--ind] = 0;
    }
  }
  cout << sum;
}