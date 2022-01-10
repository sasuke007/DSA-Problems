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
  set<int> elem;
  vector<int> input(n);
  for (int i = 0; i < n; ++i) {
    cin >> input[i];
  }
  sort(input.begin(), input.end());
  for (int i = n - 1; i >= 0; --i) {
    int val = input[i];
    while (val > 0) {
      if (val >= 1 and val <= n and elem.find(val) == elem.end()) {
        elem.insert(val);
        break;
      }
      val /= 2;
    }
  }
  cout << (elem.size() == n ? "YES" : "NO") << endl;
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