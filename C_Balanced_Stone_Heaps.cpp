#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
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
const int inf = 1e9 + 7;
bool validate(vector<int> &input, int mid) {
  vector<int> temp(input.begin(), input.end());
  for (int i = input.size() - 1; i >= 2; --i) {
    if (temp[i] < mid) {
      return false;
    }
    int d = min(temp[i] - mid, input[i]) / 3;
    temp[i - 1] += d;
    temp[i - 2] += 2 * d;
  }
  if (temp[0] >= mid and temp[1] >= mid) return true;
  return false;
}
void solve() {
  int n;
  cin >> n;
  vector<int> input(n);
  for (int i = 0; i < n; ++i) {
    cin >> input[i];
  }
  int low = 0, high = *max_element(input.begin(), input.end());
  int answer = 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (validate(input, mid)) {
      answer = max(answer, mid);
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  cout << answer << endl;
}
int main() {
  fast_cin();
  ll t;
  cin >> t;
  for (int it = 1; it <= t; it++) {
    solve();
  }
}