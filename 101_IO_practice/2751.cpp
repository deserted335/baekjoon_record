#include <iostream>
#include <algorithm>
#define LIMIT 1000000
using namespace std;

int A[LIMIT]; // target array
int tempArr[LIMIT];


void Merge(int left, int right){
  for(int i = left; i <= right; i++) tempArr[i] = A[i];

  int mid = (left + right) / 2;
  int tL = left;
  int tR = mid + 1;
  int curInd = left;

  while(tL <= mid && tR <= right){
    if(tempArr[tL] <= tempArr[tR]) A[curInd++] = tempArr[tL++];
    else A[curInd++] = tempArr[tR++];
  }

  int remain = mid - tL;
  for(int i = 0; i <= remain; i++) A[curInd + i] = tempArr[tL + i];
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

  int N;
  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];
  Partition(0, N-1);
  for(int i = 0; i < N; i++) cout << A[i] << '\n';
}