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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
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
  vector<pii> visits(n);
  for (int i = 0; i < n; ++i) {
    int elem;
    cin >> elem;
    visits[i] = {elem, i};
  }
  int curr_location = 0;
  vector<int> locations(n + 1, 0);
  sort(visits.begin(), visits.end(), greater<pair<int, int>>());
  ll total_time = 0;
  bool change = true;
  for (int i = 0; i < n; ++i) {
    if (change) {
      ++curr_location;
      change = false;
    } else {
      change = true;
    }
    pii building = visits[i];
    locations[building.second + 1] =
        ((i & 1) ? -1 * curr_location : curr_location);
    total_time += curr_location * 2ll * building.first;
  }
  cout << total_time << endl;
  cout << 0 << " ";
  for (int i = 0; i < n; ++i) {
    cout << locations[i + 1] << " ";
  }
  cout << endl;
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