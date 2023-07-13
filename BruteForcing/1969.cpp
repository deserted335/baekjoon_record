#include <iostream>
#include <string>
using namespace std;
string Words[1000];
// m : number of DNA seq, n : length of each DNA seq
int m, n;

int HammingPerIndex(int idx, char DistFrom){
  // return Hamming distance for index idx, of character DistFrom
  int Dist = 0;
  for(int seq = 0; seq < m; seq++) Dist += (Words[seq][idx] != DistFrom);
  return Dist;
}

string RepSeq(){
  // Lexicographically arranged Neucleotides
  char NucleoList[4] = {'A', 'C', 'G', 'T'};
  string ret;
  while (ret.size() != n)
  {
    int MinDist = m;
    for (int NucleoType = 0; NucleoType < 4; NucleoType++)
      MinDist = min(MinDist, HammingPerIndex(ret.size(), NucleoList[NucleoType]));
    for (int NucleoType = 0; NucleoType < 4; NucleoType++)
    {
      // Check Minimum Distance character in Lexicographical order
      if (MinDist == HammingPerIndex(ret.size(), NucleoList[NucleoType]))
      {
        ret.push_back(NucleoList[NucleoType]);
        break;
      }
    }
  }
  return ret;
}

int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  cin >> m >> n;
  for(int seq = 0; seq < m; seq++) cin >> Words[seq];
  string Res = RepSeq();
  int Dist = 0;
  for(int idx = 0; idx < n; idx++) Dist += HammingPerIndex(idx, Res[idx]);
  cout << Res << '\n' << Dist;
}