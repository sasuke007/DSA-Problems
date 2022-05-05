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

void solve() {
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  vector<vector<int> > type(2, vector<int>(2, 0));
  for (int i = 0; i < n; ++i) {
    type[a[i] - '0'][b[i] - '0']++;
  }
  int result = inf;
  if (type[0][1] == type[1][0]) {
    result = min(result, 2 * type[1][0]);
  }
  if (type[1][0] > 0) {
    int new01type = type[1][1];
    int new10type= type[0][0] + 1;
    if(new01type==new10type){
        result=min(result, 2*new01type + 1);
    }
  }
  if (type[1][1] > 0) {
      int new01type = type[1][1]-1;
      int new10type = type[0][0];
      if(new01type==new10type){
          result=min(result,2*new01type + 1);
      }
  }
  cout << ((result == inf) ? -1 : result) << endl;
}
int main() {
  fast_cin();
  ll t;
  cin >> t;
  for (int it = 1; it <= t; it++) {
    solve();
  }
}