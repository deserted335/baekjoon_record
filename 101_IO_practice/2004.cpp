#include <iostream>
using namespace std;

int fact_2s(int tmp){
  // from 1 to tmp, cnt = (# of only 5 multiples) + 2 * (# of only 5^2 multiples) + ... + i * (# of only 5^i multiples)
  //                    = (# of 5 multiples) + (# of 5^2 multiples) + ... 
  int cnt = 0;
  while(tmp / 5 != 0){
    cnt += tmp / 5;
    tmp /= 5;
  } 
  return cnt;
}


int fact_5s(int tmp){
  // same as fact_2s
  int cnt = 0;
  while(tmp / 2 != 0){
    cnt += tmp / 2;
    tmp /= 2;
  } 
  return cnt;
}


int main(){
  int n, m;
  cin >> n >> m;
  // return minimum of # of 2, # of 5 from comb(n, m) = n!/((n -m)! * m!)
  cout << min(fact_2s(n) - fact_2s(m) - fact_2s(n - m), fact_5s(n) - fact_5s(m) - fact_5s(n - m)); 
}