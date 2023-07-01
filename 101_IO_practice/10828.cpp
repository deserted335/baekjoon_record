#include <iostream>
#include <cstring>
#define LIMIT 10000
using namespace std;
int Stack[LIMIT] = {0};

int main()
{
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int N, size= 0;
  char inst[5 + 1];
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> inst; 
    if(!strcmp(inst,"push")) cin >> Stack[size++];
    else if(!strcmp(inst,"pop")) cout << ((size > 0) ? Stack[--size] : -1) << '\n';
    else if(!strcmp(inst,"size")) cout << size << "\n";
    else if(!strcmp(inst,"empty")) cout << (size == 0) << "\n";
    else if(!strcmp(inst,"top")) cout << ((size > 0) ? Stack[size - 1] : -1) << '\n';
    }
}