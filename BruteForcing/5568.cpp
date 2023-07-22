#include <iostream>
#include <vector>
#include <string>
using namespace std;
string Cards[10];
vector<string> Counted;
// give up...
// n : # of cards, k : # of possible selects
int n, k;

int isCounted(string tar){
  for(int i = 0; i < Counted.size(); i++) if(Counted[i] == tar) return 1;
  return 0;
}

int CountMakeable(){
  vector<string> tmp;
  for(int i = 0; i < n; i++) {
    tmp.push_back(Cards[i]); 
    if(!isCounted(Cards[i])) Counted.push_back(Cards[i]);
  }
  for(int i = 2; i <= k; i++){
    for(int item = 0; item < tmp.size(); item++){ 
      for(int card = 0; card < n; card++){
      }
    } 
  }
}

int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  cin >> n >> k;
  for(int i = 0; i < n; i++) cin >> Cards[i];
}