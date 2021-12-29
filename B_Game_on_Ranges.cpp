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

bool compare(pair<int, int> a, pair<int, int> b) {
  return a.second - a.first < b.second - b.first;
}
int find_element(pair<int, int> &range, set<int> &present) {
  for (int i = range.first; i <= range.second; ++i) {
    if (present.find(i) == present.end()) {
      return i;
    }
  }
  cout << "Wrong logic" << endl;
  return 0;
}

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int> > selections(n);
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    selections[i] = {a, b};
  }
  sort(selections.begin(), selections.end(), compare);
//   for (int i = 0; i < n; ++i) {
//     cout << selections[i].first << " " << selections[i].second << endl;
//   }
  set<int> present;
  for (int i = 0; i < n; ++i) {
    if (selections[i].first == selections[i].second) {
      cout << selections[i].first << " " << selections[i].second << " "
           << selections[i].first << endl;
      present.insert(selections[i].first);
    } else {
      int elem = find_element(selections[i], present);
      cout << selections[i].first << " " << selections[i].second << " " << elem
           << endl;
      present.insert(elem);
    }
  }
}
int main() {
  fast_cin();
  ll t;
  cin >> t;
  for (int it = 1; it <= t; it++) {
    solve();
    cout<<endl;
  }
}