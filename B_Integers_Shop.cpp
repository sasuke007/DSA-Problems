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
  vector<vector<ll> > segments(n, vector<ll>(3));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> segments[i][j];
    }
  }
  vector<ll> max_pair(segments[0]), min_pair(segments[0]),
      longest_pair(segments[0]);
  cout << longest_pair[2] << endl;
  for (int i = 1; i < n; ++i) {
    if (segments[i][0] < min_pair[0] or
        (segments[i][0] == min_pair[0] and segments[i][2] < min_pair[2])) {
      min_pair = segments[i];
    }
    if (segments[i][1] > max_pair[1] or
        (segments[i][1] == max_pair[1] and segments[i][2] < max_pair[2])) {
      max_pair = segments[i];
    }
    if (segments[i][0] <= longest_pair[0] and
        segments[i][1] >= longest_pair[1]) {
      if (segments[i][0] == longest_pair[0] and
          segments[i][1] == longest_pair[1] and
          segments[i][2] < longest_pair[2]) {
        longest_pair = segments[i];
      } else {
        longest_pair = segments[i];
      }
      longest_pair = segments[i];
    }
    if (longest_pair[0] == min_pair[0] and longest_pair[1] == max_pair[1] and
        longest_pair[2] < (min_pair[2] + max_pair[2])) {
      cout << longest_pair[2] << endl;
    } else {
      cout << min_pair[2] + max_pair[2] << endl;
    }
  }
}
int main() {
  fast_cin();
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ll t;
  cin >> t;
  for (int it = 1; it <= t; it++) {
    solve();
  }
}