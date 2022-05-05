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
    cin >> n;
    vector<int> map_one(n);
    for (int i = 0; i < n; ++i) {
      cin >> map_one[i];
    }
    vector<int> map_two(n);
    for (int i = 0; i < n; ++i) {
      cin >> map_two[i];
    }
    auto it = max_element(map_one.begin(), map_one.end());
    int map_one_max = *it;
    int map_one_max_index = it - map_one.begin();
    it = max_element(map_two.begin(), map_two.end());
    int map_two_max = *it;
    int map_two_max_index = it - map_two.begin();
    for (int i = 0; i < n; ++i) {
      int val_one = map_one[i];
      int val_two = map_two[i];
      if (val_one == map_one_max or val_two == map_two_max) {
        cout << 1;
      } else {
        if ((map_one[map_two_max_index] < val_one) or (map_two[map_one_max_index] < val_two)){
              cout<<1;
          }
        else {
          cout << 0;
        }
      }
    }
    cout << endl;
  }
}
