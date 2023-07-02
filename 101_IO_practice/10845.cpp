#include <iostream>
#include <cstring>
#define LIMIT 10000
using namespace std;
int Qu[LIMIT] = {0};

int main()
{
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int N, size = 0;
  char inst[5 + 1];
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> inst;
    if (!strcmp(inst, "push"))
      cin >> Qu[size++];
    else if (!strcmp(inst, "pop"))
    {
      if (size > 0)
      {
        cout << Qu[0] << "\n";
        for (int ind = 1; ind < size; ind++)
          Qu[ind - 1] = Qu[ind];
        size--;
      }
      else
        cout << -1 << "\n";
    }
    else if (!strcmp(inst, "size"))
      cout << size << "\n";
    else if (!strcmp(inst, "empty"))
      cout << (size == 0) << "\n";
    else if (!strcmp(inst, "front"))
      cout << ((size == 0) ? -1 : Qu[0]) << "\n";
    else if (!strcmp(inst, "back"))
      cout << ((size > 0) ? Qu[size - 1] : -1) << '\n';
  }
}