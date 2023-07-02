#include <iostream>
#define LIMIT 500
using namespace std;
char A[LIMIT][LIMIT + 1];
int exist[26] = {0};

int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int N, M, K;
  cin >> N >> M >> K;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      cin >> A[i][j];
      if(!exist[A[i][j] - 'A']) exist[A[i][j] - 'A'] = 1;
    }
  }
  
  int cnt, max_ind, tmp = LIMIT * LIMIT;
  for (int alp = 0; alp < 26; alp++)
  {
    if(!exist[alp]) continue;
    cnt = 0;
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < M; j++)
      {
        if(A[i][j] != char('A' + alp)) cnt++;
      }
    }
    if(tmp > cnt){
      max_ind = alp;
      tmp = cnt;
    }
  }

  for(int i = 0; i < N; i++)
    for(int j = 0; j < M; j++)
      
}