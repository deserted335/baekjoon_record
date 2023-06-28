#include <iostream>
using namespace std;

int main(){
  int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  string name[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
  int cnt = 0, month, day;
  cin >> month >> day;
  for(int i = 0; i < month - 1; i++) cnt += days[i];
  cnt += day;
  printf("%s", name[cnt%7].c_str());
}