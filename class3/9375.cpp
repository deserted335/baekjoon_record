#include <iostream>
#include <string>
#include <vector>
using namespace std;
// string : Sort of Clothes, int : # of Clothes of that Sort.
vector<pair<string, int>> WhatKindOf;

int KindIdx(string tmp){
  // WhatKindOf.size() <= 30. So total O(N^2) method is fine.
  for(int i = 0; i < WhatKindOf.size(); i++) {
    if(WhatKindOf[i].first == tmp) 
      return i;
  }
  return -1; // such Sort of clothes doesn't exist 
}

int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  // T : test cases
  int T;
  cin >> T;
  while(T--){
    WhatKindOf.clear();
    // n : # of clothes
    int n, ind;
    cin >> n;
    while(n--){
      string tmp;
      cin >> tmp;  // EXACTLY SAME clothes won't come out. this is dummy
      cin >> tmp;
      if((ind = KindIdx(tmp)) == -1) WhatKindOf.push_back(make_pair(tmp, 1));
      else WhatKindOf[ind].second += 1; 
    }
    int ret = 1;
    for(int sort = 0; sort < WhatKindOf.size(); sort++) 
      ret *= WhatKindOf[sort].second + 1; // each Kind of clothes has (# of clothes of that sort) + 1 (None) states 
    cout << ret - 1 << '\n'; // (None, None, None, ...) case subtracted
  }
}