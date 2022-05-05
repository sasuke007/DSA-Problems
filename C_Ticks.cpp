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
bool analyze(vector<vector<char> > &ticks, int x, int y, int k) {
  int n = ticks.size();
  int m = ticks[0].size();
  int i = x;
  int j = y;
  bool valid_tick = true;
  int left_length = 0;
  int right_length = 0;
  while (i >= 0 and j >= 0) {
    if (ticks[i][j] == '.') {
      break;
    } else {
      ++left_length;
      --i;
      --j;
    }
  }
  i = x;
  j = y;
  while (i >= 0 and j < m) {
    if (ticks[i][j] == '.') {
      break;
    } else {
      ++right_length;
      --i;
      ++j;
    }
  }
  if (k > min(left_length - 1, right_length - 1)) {
    valid_tick = false;
  }
  return valid_tick;
}
int mark(vector<vector<char> > &ticks, int x, int y) {
  int n = ticks.size();
  int m = ticks[0].size();
  int i = x;
  int j = y;
  int marked_ticks = 0;
  while (i >= 0 and j >= 0 and ticks[i][j] != '.') {
    if (ticks[i][j] == '*') {
      ++marked_ticks;
    }

    ticks[i][j] = '$';
    --i;
    --j;
  }
  i = x;
  j = y;
  while (i >= 0 and j < m and ticks[i][j] != '.') {
    if (ticks[i][j] == '*') {
      ++marked_ticks;
    }
    ticks[i][j] = '$';
    --i;
    ++j;
  }
  return marked_ticks;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef D_DEBUG
  freopen("input.txt", "r", stdin)
#endif
      int tc;
  cin >> tc;
  while (tc--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char> > ticks(n, vector<char>(m));
    int total_tick_cells = 0;
    int encountered_ticks = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        char ch;
        cin >> ch;
        ticks[i][j] = ch;
        if (ch == '*') {
          ++total_tick_cells;
        }
      }
    }
    if (k == n) {
      cout << "NO" << endl;
    } else {
      for (int i = k; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (ticks[i][j] != '.') {
            bool valid_tick = analyze(ticks, i, j, k);
            if (valid_tick) {
              encountered_ticks += mark(ticks, i, j);
            }
          }
        }
      }
      if (encountered_ticks == total_tick_cells) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
    // for (int i = 0; i < n; ++i) {
    //   for (int j = 0; j < m; ++j) {
    //     cout << ticks[i][j] << " ";
    //   }
    //   cout << endl;
    // }
  }
}