#include <iostream>
#include <string>
#include <algorithm>
#define LIMIT 100000
using namespace std;
pair<string, int> Monsters[LIMIT + 1];
pair<string, int> Sorted_Monsters[LIMIT + 1];

bool isInteger(string tmp){
  if(tmp[0] <= '0' || tmp[0] > '9') 
    return false;
  for(int idx = 1; idx < tmp.size(); idx++) 
    if(tmp[idx] < '0' || tmp[idx] > '9') 
      return false;
  return true;
}

int Bin_Search(string tar, int start, int end){
  // if exists (in this case exists. So ignore Don't Exist), return index of that Monster
  // base case : start or end index is right
  if(Sorted_Monsters[start].first == tar) return Sorted_Monsters[start].second;
  else if(Sorted_Monsters[end].first == tar) return Sorted_Monsters[end].second;
  else if(start == end) return Sorted_Monsters[start].second;

  int mid = (start + end) / 2;
  if(Sorted_Monsters[mid].first < tar)  return Bin_Search(tar, mid + 1, end);
  else return Bin_Search(tar, start, mid);
}

bool compare(const pair<string, int>& a, const pair<string, int>& b){
  return a.first < b.first;
}

int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  // N : # of monsters, M : # of problems
  int N, M;
  cin >> N >> M;
  for(int i = 1; i <= N; i++){
    string tmp_Monster;
    cin >> tmp_Monster;
    Sorted_Monsters[i] = Monsters[i] = make_pair(tmp_Monster, i);
  }

  sort(Sorted_Monsters + 1, Sorted_Monsters + N + 1, compare);

  while(M--){
    string tmp;
    cin >> tmp;
    if(isInteger(tmp)) cout << Monsters[stoi(tmp)].first << '\n';
    else cout << Bin_Search(tmp, 1, N) << '\n';
    }
}