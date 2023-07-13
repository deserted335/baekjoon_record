#include <iostream>
#include <string>
using namespace std;
float KgToLb = 2.2046;
float LToG = 0.2642;
float LbToKg = 0.4536;
float GToL = 3.7854;

int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int T;
  cin >> T;
  for(int t = 1; t <= T; t++){
    float val;
    string unit;
    cin >> val >> unit;
    printf("%d ", t);
    if(unit == "kg") printf("%.4f lb\n", val * KgToLb);
    else if(unit == "l") printf("%.4f g\n", val * LToG);
    else if(unit == "lb") printf("%.4f kg\n", val * LbToKg);
    else if(unit == "g") printf("%.4f l\n", val * GToL);
  }
}