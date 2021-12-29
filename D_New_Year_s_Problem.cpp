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
bool verify(vector<vector<int> > &joy, int mid) {
  bool two_gifts_from_one_store = false;
  bool possible = true;
  int friends = joy[0].size();
  int stores = joy.size();
  set<int> friend_stores;
  for (int i = 0; i < stores; ++i) {
      int satisfied_friends = 0;
    for (int j = 0; j < friends; ++j) {
        if(joy[i][j] >= mid){
            ++satisfied_friends;
            friend_stores.insert(j);
        }
    }
    if(satisfied_friends>=2){
        two_gifts_from_one_store = true;
    }
  }
  if(friend_stores.size()==friends and two_gifts_from_one_store){
      return true;
  }
  return false;
}
void solve() {
  int n, m;
  cin >> m >> n;
  vector<vector<int> > joy(m, vector<int>(n));
  int max_joy = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> joy[i][j];
      max_joy = max(max_joy, joy[i][j]);
    }
  }
  int answer = 1;
  ;
  int low = 1, high = max_joy;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (verify(joy, mid)) {
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