// // By Brute Force, time excess
// #include <iostream>
// #include <vector>
// #define LIMIT 100000
// using namespace std;
// vector<int> arr(LIMIT);

// int main(){
//   cin.tie(NULL);
//   ios::sync_with_stdio(false);

//   int N, M;
//   cin >> N >> M;
//   for(int i = 0; i < N; i++) cin >> arr[i];
//   for(int _i = 0; _i < M; _i++){
//     int from, to, sum = 0;
//     cin >> from >> to;
//     for(int i = from - 1; i < to; i++)
//       sum += arr[i];
//     cout << sum << '\n';
//   }
// }

#include <iostream>
#include <vector>
using namespace std;
struct RMQ {
  int n;

  vector<int> rangeSum;
  RMQ(const vector<int>& array) {
    n = array.size();
    rangeSum.resize(n * 4);
    init(array, 0, n - 1, 1);
  }

  int init(const vector<int>& array, int left, int right, int node){
    if(left == right) return rangeSum[node] = array[left];
    int mid = (left + right) / 2;
    int leftMin = init(array, left, mid, node * 2);
    int rightMin = init(array, mid + 1, right, node * 2 + 1);
    return rangeSum[node] = leftMin + rightMin;
  }

  int query(int left, int right, int node, int nodeLeft, int nodeRight){
    if(right < nodeLeft || left > nodeRight) return 0;

    if(left >= nodeLeft && right <= nodeRight) return rangeSum[node];

    int mid = (nodeLeft + nodeRight) / 2;
    return query(left, right, node*2, nodeLeft, mid) + query(left, right, node*2 + 1, mid + 1, nodeRight);
  }

  int query(int left, int right){
    return query(left, right, 1, 0, n-1);
  }
};

int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int N, M;
  vector<int> Nums, tar;
  cin >> N >> M;
  for(int i = 1; i <= N; i++) cin >> Nums[i];
  struct RMQ SegTree{N, tar, RMQ(Nums)};
  

}