#include <iostream>
#include <queue>
using namespace std;
queue<int> Qu, Seq;

int main(){
  int N, K;
  cin >> N >> K;
  for(int i = 1; i <= N; i++) Qu.push(i);
  while(!Qu.empty()){
    for(int i = 0; i < K - 1; i++){
    Qu.push(Qu.front());
    Qu.pop();
    }
    Seq.push(Qu.front()); 
    Qu.pop();
  }

  cout << "<";
  while(Seq.size() != 1){
    cout << Seq.front() << ", ";
    Seq.pop();
  }
  cout << Seq.front() << ">";
}