#include <iostream>
using namespace std;

int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  int x_ans = 1000, y_ans = 1000;
  for(int x = -999; x < 1000; x++){
    for(int y = -999; y < 1000; y++){
      if(a * x + b * y == c && d * x + e * y == f) {
        x_ans = x, y_ans = y; 
        break;
      }
    }
    if(x_ans != 1000 || y_ans != 1000) break;
  }
  cout << x_ans << " " << y_ans; 
}