#include <iostream>
#include <string>
using namespace std;

int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int T;
  cin >> T;
  for(int t = 1; t <= T; t++){
    int rmv;
    string tmp;
    cin >> rmv >> tmp;
    cout << t << " " << tmp.erase(rmv - 1, 1) << '\n';
  }
}