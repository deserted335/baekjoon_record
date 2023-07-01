#include <iostream>
#define LIMIT 100000
using namespace std;
int A[LIMIT][2];
int tempArr[LIMIT][2];

int is_increasing(int tL, int tR){
  return tempArr[tL][0] < tempArr[tR][0] || (tempArr[tL][0] == tempArr[tR][0] && tempArr[tL][1] <= tempArr[tR][1]);
}


void Merge(int left, int right){
  for(int i = left; i <= right; i++) {
    // initial assignment
    tempArr[i][0] = A[i][0];
    tempArr[i][1] = A[i][1];
  }

  int mid = (left + right) / 2;
  int tL = left;
  int tR = mid + 1;
  int curInd = left;

  while(tL <= mid && tR <= right){
    // mono-increasing condition
    if(is_increasing(tL, tR)) {
      // assignment 
      A[curInd][0] = tempArr[tL][0];
      A[curInd++][1] = tempArr[tL++][1];
    }
    else {
      A[curInd][0] = tempArr[tR][0];
      A[curInd++][1] = tempArr[tR++][1];
    }
  }

  int remain = mid - tL;
  for(int i = 0; i <= remain; i++) {
    // assignment
    A[curInd + i][0] = tempArr[tL + i][0];
    A[curInd + i][1] = tempArr[tL + i][1];
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
  int N;
  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i][0] >> A[i][1];
  Partition(0, N-1);
  for(int i = 0; i < N; i++) cout << A[i][0] << " " << A[i][1] << '\n';
}