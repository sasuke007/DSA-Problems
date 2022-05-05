#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>
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
  while (tc--) {
    int n;
    cin >> n;
    vector<int> input(n);
    for (int i = 0; i < n; ++i) {
      cin >> input[i];
    }
    int max = *max_element(input.begin(), input.end());
    if (input[0] == max or input[n - 1] == max) {
      deque<int> d;
      int i = 0, j = n - 1;
      while (i < j) {
        if (input[i] < input[j]) {
          d.push_front(input[i]);
          ++i;
        } else {
          d.push_back(input[j]);
          --j;
        }
      }
      if (max == input[0]) {
        d.push_front(max);
      } else {
        d.push_back(max);
      }
      while (!d.empty()) {
        cout << d.front() << " ";
        d.pop_front();
      }
      cout<<endl;
    } else {
      cout << -1 << endl;
    }
  }
}