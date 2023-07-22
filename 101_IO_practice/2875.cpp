#include <iostream>
using namespace std;

int main(){
  int N, M, K, teams;
  cin >> N >> M >> K;
  if(M > N / 2){
    teams = N / 2;
    M -= N / 2;
    N = 0; 
  }
  else{
    teams = M;
    N -= M * 2;
    M = 0;
  }

  int total = M + N;
  while(total < K){
    teams -= 1;
    total += 3;
  }
  cout << teams;
}

// // Greedy Solution. 
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);
// 	int n, m, k;
// 	cin >> n >> m >> k;
// 	while(k--){
// 		if(n > 2*m) n--;
// 		else m--;
// 	}
// 	cout << min(n/2, m);
// }