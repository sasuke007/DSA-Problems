#include <bits/stdc++.h>

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

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
#define fast_cin()                  \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define endl "\n"
#define debug(x) cout << #x << " " << x << endl;

void solve() {
  int n;
  cin >> n;
  vector<int> input(n);
  for (int i = 0; i < n; ++i) {
    cin >> input[i];
  }
  if (n == 1) {
    cout << 0 << endl;
    return;
  }
  // sort(input.begin(), input.end());
  int answer = n - 1;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      double diff = (input[j] - input[i] * 1.0) / ((j - i) * 1.0);
      int changed_elements = 0;
      for (int k = 0; k < n; ++k) {
        double d = (input[k] - input[i] * 1.0) - (k - i) * diff;
        d = abs(d);
        if (d >= 0.0000000001) {
          changed_elements++;
        }
      }
      answer = min(answer, changed_elements);
    }
  }
  cout << answer << endl;
}
int main() {
  fast_cin();
#ifdef D_DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ll t;
  cin >> t;
  for (int it = 1; it <= t; it++) {
    solve();
  }
}