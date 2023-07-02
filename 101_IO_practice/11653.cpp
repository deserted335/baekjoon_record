#include <iostream>
#define LIMIT 10000000
using namespace std;
int is_P[LIMIT + 1];


int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);


  int N, t;
  cin >> N;
  t = N;
  if(N == 1) return 0;

  // Eratos
  fill_n(is_P, N + 1, -1);
  is_P[1] = 0;
  for(int i = 2; i <= N; i++){
    if(is_P[i] == 0) continue;
    for(int j = 2*i; j <= N; j += i) is_P[j] = 0;
  }

  // 
  for(int i = 2; i <= N; i++){
    if(t == 1) return 0;
    if(is_P[i] == 0) continue;
    while(t % i == 0){
      cout << i << '\n';
      t /= i;
    }   
  }
}

// // with Eratos
// #include <iostream>

// using namespace std;

// int main() {
//     int n;
//     cin >> n;
//     for(int i=2; i*i<=n;) {
//         if(n % i == 0) {
//             n /= i;
//             cout << i << endl;
//         }else i++;
//     }
//     if(n>1) cout << n << endl;
//     return 0;
// }