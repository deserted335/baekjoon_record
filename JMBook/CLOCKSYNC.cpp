#include <iostream>
#define INF 987654321
using namespace std;
// regularized clock {3, 6, 9, 12} => {0, 1, 2, 3}
int clocks[16];
// if ButtonClick, clocks are added each indexes of buttontypes.
// buttons[buttontype][clockIndex] : buttontype 0 ~ 9, clockIndex 0 ~ 15.
int buttons[10][16] = {{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,0},
                        {0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1},
                        {1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,1,1,1,0,1,0,1,0,0,0},
                        {1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
                        {0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1},
                        {0,0,0,0,1,1,0,1,0,0,0,0,0,0,1,1},
                        {0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,1,1,1,0,0,0,1,0,0,0,1,0,0}};

int Twelves(int* CLK){
  // return count of Twelves of input clock CLK.
  int cnt = 0;
  for(int i = 0; i < 16; i++) if(CLK[i] == 3) cnt++;
  return cnt;
}

void ButtonClick(int* CLK, int ButtonIdx){
  // Execute Button of which type is ButtonIdx to the input clock CLK
  for(int CLKIdx = 0; CLKIdx < 16; CLKIdx++) {
    CLK[CLKIdx] += buttons[ButtonIdx][CLKIdx];
    CLK[CLKIdx] %= 4;
  }
}

int HowMuchClick(int* CLK, int CurrentClick){
  // returns minimum button clicks for clock to sync all twelve.
  int CurTwelve = Twelves(CLK);
  // base case : if sync, return current click executes.
  if(CurTwelve == 16) return CurrentClick;
  // base case : if no Twelve changes after all ButtonClick tries, return -1
  int ret = INF;
  for(int ButtonType = 0; ButtonType < 10; ButtonType++){
    for(int cnt = 1; cnt <= 3; cnt++){
      ButtonClick(CLK, ButtonType);
      if(CurTwelve <= Twelves(CLK)) // this is Greedy!! NOT BRUTEFORCE
        ret = min(ret, HowMuchClick(CLK, CurrentClick + cnt));
    }
    ButtonClick(CLK, ButtonType); // return to initial state (4th click)
  }
  return ret;
}

int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int T;
  cin >> T;
  while(T--){
    int tmp;
    for(int i = 0; i < 16; i++){
      cin >> tmp;
      // regularize clocks
      clocks[i] = tmp / 4; 
    }
    int out = HowMuchClick(clocks, 0);
    cout << (out == INF ? -1 : out) << '\n'; 
  }
}