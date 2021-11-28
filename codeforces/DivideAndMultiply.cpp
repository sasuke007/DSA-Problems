#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>
#include<math.h>
using namespace std;
#define endl "\n"
typedef long long ll;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
#endif
  int tc;
  cin >> tc;
  int inf = 1e9 + 7;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> input(n);
    for (int i = 0; i < n; ++i) {
      cin >> input[i];
    }
    int total_powers = 0;
    for (int i = 0; i < n; ++i) {
      int count = 0;
      int temp = input[i];
      while (input[i] % 2 == 0) {
        count++;
        input[i] /= 2;
      }
      total_powers += count;
    }
    sort(input.begin(), input.end());
    ll sum = accumulate(input.begin(), input.end(), 0l);
    sum -= input[n - 1];
    sum+=input[n-1]*pow(2,total_powers);
    cout<<sum<<endl;
  }
}