#include <iostream>
#include <vector>
using namespace std;
// LIS(Longest Increasing Subsequence) problem. in DP
// input : int array A.
// output : size of LIS of A

// Brute-force algorithm for lis problem. O(n^2)
// count Increasing Subsequence from A[0] to A[n-1]
int lis(const vector<int>& A){
  // base case : A is empty
  if(A.empty()) return 0;
  int ret = 0;
  for(int i = 0; i < A.size(); i++){
    vector<int> B;
    for(int j = i+1; j < A.size(); j++)
      if(A[i] < A[j])
        B.push_back(A[j]);
    ret = max(ret, 1 + lis(B));
  }
  return ret;  // return maximum value 
}

// subproblem change. Starting index matters.
// LIS_DP(int start) : returns size of LIS starting at index = start
#define LIMIT 100
int sizeofS;
int cache[LIMIT], S[LIMIT];
int lisDP(int start){  
  // cache filled with -1 (not cached) required
  int& ret = cache[start];
  if(ret != -1) return ret; // if cached, return it

  ret = 1; // including S[start] 
  for(int next = start+1; next < sizeofS; next++)    
    if(S[start] < S[next])
      ret = max(ret, lisDP(next) + 1); // call lis of next increasing index
  return ret;
} // Then, find start index which has maximum lis by For.
// O(n^2)

// Without For ver.
#define LIMIT 100
int sizeofS;
// by cache[0] = -inf, try every start index. 
int cache[LIMIT + 1], S[LIMIT + 1];
int lisDPimproved(int start){
  // cache filled with -1 (not cached) required
  int& ret = cache[start];
  if(ret != -1) return ret; // if cached, return it

  ret = 1; // including S[start] 
  for(int next = start+1; next < sizeofS; next++)    
    if(start == 0 || S[start] < S[next])
      ret = max(ret, lisDP(next) + 1); // call lis of next increasing index
  return ret;
} // Then lisDPimproved[0] - 1 is answer as ret = 1 at idx = 0

// O(nlgn) Algorithm -> Subproblem : Later...

// JMBook example. 