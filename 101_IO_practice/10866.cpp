#include <iostream>
#include <cstring>
#define LIMIT 10000
#define MAX_LEN 10
using namespace std;
int D[LIMIT] = {0};

int main()
{
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int N, size = 0;
  char inst[MAX_LEN + 1];
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> inst;
    if(!strcmp(inst, "push_front")){
      for(int ind = size-1; ind >= 0; ind--) D[ind + 1] = D[ind];
      cin >> D[0];
      size++;
    }
    if (!strcmp(inst, "push_back")) cin >> D[size++];
    else if (!strcmp(inst, "pop_front")) {
      if (size > 0) {
        cout << D[0] << "\n";
        for (int ind = 1; ind < size; ind++) D[ind - 1] = D[ind];
        size--;
      }
      else cout << -1 << "\n";
    }
    else if (!strcmp(inst, "pop_back")) cout << ((size > 0) ? D[--size] : -1) << "\n";
    else if (!strcmp(inst, "size")) cout << size << "\n";
    else if (!strcmp(inst, "empty")) cout << (size == 0) << "\n";
    else if (!strcmp(inst, "front")) cout << ((size > 0) ? D[0] : -1) << "\n";
    else if (!strcmp(inst, "back")) cout << ((size > 0) ? D[size - 1] : -1) << '\n';
  }
}