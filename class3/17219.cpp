#include <iostream>
#include <string>
#include <algorithm>
#define LIMIT 100000
using namespace std;
pair<string, string> URLnPW[LIMIT];

bool compare(const pair<string, string>& a, const pair<string, string>& b){
  return a.first < b.first;
}

int BinSearchIdx(string tar, int start, int end){
  // Binary Search for target string in Array.
  // output target index if exists, otherwise -1 (not necessary this case)
  // base case : target is in start or end index.
  if(URLnPW[start].first == tar) return start; 
  else if(URLnPW[end].first == tar) return end;
  // fail case : start == end but target not searched.
  else if(start == end) return -1;

  int mid = (start + end) / 2;
  if(URLnPW[mid].first < tar) return BinSearchIdx(tar, mid + 1, end);
  else return BinSearchIdx(tar, start, mid);
}

int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  // N : # of Site, M : # of Wanna-find Sites
  int N, M;
  cin >> N >> M;
  for(int i = 0; i < N; i++){
    string URL, PW;
    cin >> URL >> PW;
    URLnPW[i] = make_pair(URL, PW);
  }
  
  sort(URLnPW, URLnPW + N, compare);

  while(M--){
    string tmp;
    cin >> tmp;
    cout << URLnPW[BinSearchIdx(tmp, 0, N - 1)].second << '\n';
  }
}