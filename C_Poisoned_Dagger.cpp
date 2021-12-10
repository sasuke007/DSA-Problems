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
  while (tc--) {
    ll n, h;
    cin >> n >> h;
    vector<ll> input(n);
    for (int i = 0; i < n; ++i) {
      cin >> input[i];
    }
    input.push_back(LLONG_MAX);
    ll low = 0, high = h;
    ll answer = high;
    while (low <= high) {
      ll mid = low + (high - low) / 2;
      ll harm = 0;
      for (int i = 1; i < input.size(); ++i) {
        harm += min(input[i] * 1ll - input[i - 1], mid);
      }
      if (harm >= h) {
        answer = min(answer, mid);
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    cout << answer << endl;
  }
}