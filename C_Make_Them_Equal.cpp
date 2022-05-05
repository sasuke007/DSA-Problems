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
    int n;
    char c;
    cin >> n >> c;
    string str;
    cin >> str;
    int answer = 0;
    bool zero = true;
    for (int i = 0; i < n; ++i) {
      if (str[i] != c) {
        zero = false;
        break;
      }
    }
    if (zero) {
      cout << 0 << endl;
      continue;
    }
    bool one = false;
    for (int i = 2; i <= n; ++i) {
      int possible = true;
      for (int j = i; j <= n; j += i) {
        if (str[j - 1] != c) {
          possible = false;
          break;
        }
      }
      if (possible) {
        one = true;
        cout << 1 << endl << i << endl;
        break;
      }
    }
    if (!one) {
      cout << 2 << endl << n << " " << n - 1 << endl;
    }
  }
}