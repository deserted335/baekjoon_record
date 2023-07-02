#include <iostream>
using namespace std;
#define STR_LIMIT 100
int cnt[26];
char S[STR_LIMIT + 1];

int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  char tmp;
  cin >> S;
  fill_n(cnt, 26, -1);

  for(int ind = 0; tmp = S[ind]; ind++) cnt[tmp - 'a'] == -1 ? cnt[tmp - 'a'] = ind : 1;

  for(int i = 0; i < 26; i++) cout << cnt[i] << " ";
}