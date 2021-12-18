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
    int w, h;
    cin >> w >> h;
    vector<int> x1, x2, y1, y2;
    int l;
    cin >> l;
    for (int i = 0; i < l; ++i) {
      int val;
      cin >> val;
      x1.push_back(val);
    }
    cin >> l;
    for (int i = 0; i < l; ++i) {
      int val;
      cin >> val;
      x2.push_back(val);
    }
    cin >> l;
    for (int i = 0; i < l; ++i) {
      int val;
      cin >> val;
      y1.push_back(val);
    }
    cin >> l;
    for (int i = 0; i < l; ++i) {
      int val;
      cin >> val;
      y2.push_back(val);
    }
    ll x1_base = (x1[x1.size() - 1] - x1[0]) * 1ll * h;
    ll x2_base = (x2[x2.size() - 1] - x2[0]) * 1ll * h;
    ll y1_base =  (y1[y1.size() - 1] - y1[0]) * 1ll * w;
    ll y2_base = (y2[y2.size() - 1] - y2[0]) * 1ll * w;
    ll temp1 = max(x1_base, x2_base);
    ll temp2 = max(y1_base, y2_base);
    cout << max(temp1, temp2) << endl;
  }
}