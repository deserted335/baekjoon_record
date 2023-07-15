#include <iostream>
#include <vector>
using namespace std;
vector<vector<pair<int, int>>> Groups;

int L1Norm(const pair<int, int>& a, const pair<int, int>& b){
  return abs(a.first - b.first) + abs(a.second - b.second);
}

bool ConnectedWith(int x, int y){
  // return true if (x,y) is connected with some Groups(and merge them) / false o.w.
  // Connected With Group[i] iff there exists cabbage whose L1 Norm with (x, y) is 1 in Group[i]
  if(Groups.size() == 0) return false;

  pair<int, int> tar = make_pair(y, x);
  vector<int> adj_group_idx;
  for(int group = 0; group < Groups.size(); group++){
    for(int cab = 0; cab < Groups[group].size(); cab++){
      if(L1Norm(tar, Groups[group][cab]) == 1) adj_group_idx.push_back(group);
    }
  }
  if(adj_group_idx.size() == 0) return false;

  vector<pair<int, int>> tmp = Groups[adj_group_idx[0]];
  Groups.erase(Groups.begin() + adj_group_idx[0]);
  for (int merge = 1; merge < adj_group_idx.size(); merge++){
    tmp.insert(tmp.end(), Groups[adj_group_idx[merge]].begin(), Groups[adj_group_idx[merge]].end());
    Groups.erase(Groups.begin() + adj_group_idx[merge]);
  }
  Groups.push_back(tmp);

  return true; // Connected and merged...no. exact same group may be merged. and does erase function work this way?
}

int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int Testcase;
  cin >> Testcase;
  while(Testcase--){
    Groups.clear();
    int Width, Height, cabbages;
    cin >> Height >> Width >> cabbages;
    while(cabbages--){
      int y, x, ind;
      cin >> x >> y;
      if(!ConnectedWith(x, y)) Groups.push_back({make_pair(y, x)});
    }
    cout << Groups.size() << '\n';
  }
}