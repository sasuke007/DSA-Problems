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
    vector<int> input(n);
    for (int i = 0; i < n; ++i) {
      cin >> input[i];
    }
    ll sum = accumulate(input.begin(), input.end(), 0ll);
    ll answer = 0;
    // cout<<sum<<endl;
    unordered_map<int, int> freq;
    if (((2 * sum) % n) == 0) {
      int val = (2 * sum) / n;
      for (int i = 0; i < n; ++i) {
        freq[input[i]]++;
      }
      sort(input.begin(), input.end());
      vector<int>::iterator end = unique(input.begin(), input.end());
      input.resize(distance(input.begin(), end));
      for (int i = 0; i < input.size(); ++i) {
        int first = input[i];
        int second = val - first;
        if (first == second) {
          answer += (freq[first] * 1ll * (freq[first] - 1)) / 2;
        } else {
          answer += freq[first] * 1ll * freq[second];
        }
        freq[first] = 0;
      }
    }
    cout << answer << endl;
  }
}