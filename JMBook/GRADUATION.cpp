#include <iostream>
using namespace std;
int Pre[12] = {0};
int Available[10] = {0};

// 0 ~ N-1 th 과목까지 순서대로 가능하기만 하면 듣는 방법을 택했는데, 
// 어느 순간 어떤 때는 그 학기에만 열리는 과목이 있을 수도 있고, 그 경우의 수가 한 가지가 아니라는 걸 떠올렸다.
// 진작 dp라는 걸 떠올렸어야 하는 데 한 시간 동안 열심히 코드만 짜다가 예제를 해석하지도 않고 문제에 돌입해 버려 시간만 날렸다.
// 구현은 나중에 dp도 끝냈을 때 다시 와서 해야겠다.

int main(){
  int C;
  cin >> C;
  while(C--){
    int N, K, M, L;
    cin >> N >> K >> M >> L;

    // 과목 당 필수 이수 과목들 기록
    for(int i = 0; i < N; i++){
      int pre_n, tmp;
      cin >> pre_n;
      while(pre_n--){
        cin >> tmp;
        Pre[i] |= (1 << tmp);
      }
    }
    // 개설되는 과목들 기록
    for(int i = 0; i < M; i++){
      int sub_n, tmp;
      cin >> sub_n;
      while(sub_n--){
        cin >> tmp;
        Available[i] |= (1 << tmp);
      }
    }

    // not taken, should be finished 
    int Shoulds = (1 << N) - 1;
    for(int SEM = 0; SEM < M; SEM++){
      // Subject finishing Current semester
      int Cur_Sub = 0;
      // Available at this semester and did not finished
      Available[SEM] &= Shoulds;

      for(int i = 0; i < N; i++)
        // for available subjects and prerequisites are all finished (Shoulds => 0)
        if((Available[SEM] & (1 << i)) && !(Shoulds & Pre[i])) Cur_Sub |= (1 << i);
      
      // update Shoulds this semester
      Shoulds &= ~Cur_Sub; 

      if(Shoulds == 0) {
        cout << SEM + 1 << '\n';
        break;
      }
    }
    if(Shoulds != 0) cout << "IMPOSSIBLE" << '\n';
  }
}