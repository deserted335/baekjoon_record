#include <iostream>
#include <stdio.h>
#define LIMIT 100000 
#define STR_LIMIT 100
using namespace std;
// A[i] : age of ith human
int A[LIMIT];
// we sort index seq
int tempArr[LIMIT];
int seq[LIMIT];
char name[LIMIT][STR_LIMIT + 1];

int is_increasing(int tL, int tR){
  // compare A value of index seq
  return A[tempArr[tL]] <= A[tempArr[tR]];
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
    cin >> A[i] >> name[i];
    seq[i] = i;
  }
  Partition(0, N-1);
  for(int i = 0; i < N; i++) cout << A[seq[i]] << " " << name[seq[i]] << '\n'; 
}