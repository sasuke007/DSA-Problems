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
ll deliver_package(vector<int> &locations, unordered_map<int, int> &freq,
                    int k) {
  ll distance = 0;
  int n = locations.size();
  int items = k;
  int i = n - 1, j = n - 1;
  while (i >= 0 and j >= 0) {
    while (items > 0 and i >=0 and j >= 0) {
      ll delivered = min(freq[locations[j]], items);
      items -= delivered;
      freq[locations[j]] -= delivered;
      if (freq[locations[j]] == 0) {
        --j;
      }
    }
    items = k;
    distance += 2 * abs(locations[i]);
    i = j;
  }
  return distance;
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
    int n, k;
    cin >> n >> k;
    vector<int> positive, negative;
    unordered_map<int, int> freq;
    for (int i = 0; i < n; ++i) {
      int val;
      cin >> val;
      freq[val]++;
      if (val >= 0) {
        positive.push_back(val);
      } else {
        negative.push_back(val);
      }
    }
    sort(positive.begin(), positive.end());
    sort(negative.begin(), negative.end());
    reverse(negative.begin(), negative.end());
    positive.resize(
        distance(positive.begin(), unique(positive.begin(), positive.end())));
    negative.resize(
        distance(negative.begin(), unique(negative.begin(), negative.end())));
    ll min_distance = 0;
    ll positive_distance = deliver_package(positive, freq, k);
    ll negative_distance = deliver_package(negative, freq, k);
    ll positive_first =
        positive_distance + negative_distance -
        (negative.size() > 0 ? abs(negative[negative.size() - 1]) : 0);
    ll negative_first =
        positive_distance + negative_distance -
        (positive.size() > 0 ? positive[positive.size() - 1] : 0);
    cout << min(positive_first, negative_first)<<endl;
  }
}