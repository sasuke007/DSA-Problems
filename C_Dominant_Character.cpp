#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <algorithm>
#include <chrono>
#include <cmath>
#include <complex>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define endl "\n"

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<vector<ll> > vvl;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef D_DEBUG
  freopen("input.txt", "r", stdin)
#endif
      int tc;
  cin >> tc;
  int inf = 1e9 + 7;
  while (tc--) {
    int n;
    cin >> n;
    string input;
    cin >> input;
    int ans = inf;
    vector<int> lengths;
    for (int i = 2; i <= 7; ++i) {
      lengths.push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        int a=0,b=0,c=0;
      for (int j = i; j < min(i + 7, n); ++j) {
        if (input[j] == 'a') {
          ++a;
        }
        if (input[j] == 'b') {
          ++b;
        }
        if (input[j] == 'c') {
          ++c;
        }
        if (a + b + c > 1 and a > b and a > c) {
          ans = min(ans, j-i+1);
        }
      }
    }
    if (ans == inf) {
      ans = -1;
    }
    cout << ans << endl;
  }
}
