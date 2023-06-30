#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#define LIMIT 100000 
#define STR_LIMIT 10
using namespace std;
// we sort index seq
int tempArr[LIMIT];
int seq[LIMIT];

char name[LIMIT][STR_LIMIT + 1];
int kuk[LIMIT], young[LIMIT], su[LIMIT];

// don't work

bool is_increasing(int tL, int tR){
  // compare scores, name of index seq
  int kuk_diff = kuk[seq[tR]] - kuk[seq[tL]];
  int young_diff = young[seq[tR]] - young[seq[tL]];
  int su_diff = su[seq[tR]] - su[seq[tL]];

  if(kuk_diff == 0){
    if(young_diff == 0){
      if(su_diff == 0){
        return strcmp(name[seq[tR]], name[seq[tL]]) > 0;
      } 
      else return su_diff < 0;
    }
    else return young_diff > 0;
  }
  else return kuk_diff < 0;
}

void Merge(int left, int right){
  for(int i = left; i <= right; i++) {
    // initial assignment
    tempArr[i] = seq[i];
  }

  int mid = (left + right) / 2;
  int tL = left;
  int tR = mid + 1;
  int curInd = left;

  while(tL <= mid && tR <= right){
    // mono-increasing condition
    if(is_increasing(tL, tR)) {
      // assignment on index seq
      seq[curInd++] = tempArr[tL++];
    }
    else {
      seq[curInd++] = tempArr[tR++];
    }
  }

  int remain = mid - tL;
  for(int i = 0; i <= remain; i++) {
    // assignment on index seq
    seq[curInd + i] = tempArr[tL + i];
  }
}

void Partition(int left, int right){
  if(left < right){
    int mid = (left + right) / 2;
    Partition(left, mid);
    Partition(mid + 1, right);
    Merge(left, right);  
  }
}

int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> name[i] >> kuk[i] >> young[i] >> su[i];
    seq[i] = i;
  }
  Partition(0, N-1);
  cout << '\n';
  for(int i = 0; i < N; i++) cout << name[seq[i]] << " " <<  kuk[seq[i]] << " "<< young[seq[i]] << " " << su[seq[i]]<< '\n'; 
}