#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define LIMIT 500000
using namespace std;
string Member[LIMIT];
vector<string> DeutBo;

string BinSearch(string tar, int start, int end){
  // Binary Search for target string in Member.
  // output True for exists, false otherwise.
  // base case : target is in start or end index.
  if(Member[start] == tar) return tar;
  else if(Member[end] == tar) return tar;
  // fail case : start == end but target not searched.
  else if(start == end) return "-1";

  int mid = (start + end) / 2;
  if(Member[mid] < tar) return BinSearch(tar, mid + 1, end);
  else return BinSearch(tar, start, mid);
}

int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  // N : # not heard, M : # not seen
  int N, M;
  cin >> N >> M;
  for(int i = 0; i < N; i++) cin >> Member[i];
  sort(Member, Member + N);
  for(int i = 0; i < M; i++){
    string tmp;
    cin >> tmp;
    if(BinSearch(tmp, 0, N - 1) != "-1") DeutBo.push_back(tmp);
  } 
  cout << DeutBo.size() << '\n';
  sort(DeutBo.begin(), DeutBo.end());
  for(int i = 0; i < DeutBo.size(); i++) cout << DeutBo[i] << '\n'; 
}