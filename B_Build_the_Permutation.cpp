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

void solve() {
  int n, maxima, minima;
  cin >> n >> maxima >> minima;
  vector<int> permutation(n, -1);
  if ((maxima + minima > (n - 2)) or abs(maxima - minima) > 1) {
    cout << -1 << endl;
  } else {
    int min_start = 1;
    int max_start = n;
    if (maxima > minima) {
      int i = 1;
      while (maxima--) {
        permutation[i] = max_start;
        --max_start;
        i += 2;
      }
      for (int i = 0; i < n; ++i) {
        if (permutation[i] == -1) {
          permutation[i] = max_start;
          --max_start;
        }
      }
    } else if (maxima < minima) {
      int i = 1;
      while (minima--) {
        permutation[i] = min_start;
        ++min_start;
        i += 2;
      }
      for (int i = 0; i < n; ++i) {
        if (permutation[i] == -1) {
          permutation[i] = min_start;
          ++min_start;
        }
      }
    } else {
      int i = 1;
      while (maxima--) {
        permutation[i] = max_start;
        max_start--;
        i += 2;
      }
      for (int i = 0; i < n; ++i) {
        if (permutation[i] == -1) {
          permutation[i] = min_start;
          ++min_start;
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      cout << permutation[i] << " ";
    }
    cout << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
#endif
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
}