#include <iostream>
#define mod 20091101
using namespace std;
int Dolls[100000 + 1] = {0};
int Psum[100000 + 1] = {0};


int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;
  while(T--){
    int N, K, A1 = 0, A2 = 0;
    cin >> N >> K;

    // Originally, I tried non-mod K ver.
    for(int i = 1; i <= N; i++) {
      cin >> Dolls[i];
      if(i == 1) Psum[i] = Dolls[i] % K;
      else Psum[i] = (Dolls[i] + Psum[i - 1]) % K;
    }


    for(int t = 1; t <= N; t++){
      for(int h = 0; h < t; h++){
        if((Psum[t] - Psum[h]) % K == 0) A1++;
      }
      A1 %= mod;
    }

    int fin = 0;
    for(int t = 1; t <= N; t++){
      for(int h = 0; h < t; h++){
        if(t < fin || h < fin) continue;
        if((Psum[t] - Psum[h]) % K == 0) {
          A2++;
          fin = t;
        }
      }
    }

    cout << A1 << " " << A2 << '\n';
  }
}