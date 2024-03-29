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
    vector<int> next_greater(n, -1);
    stack<int> st;
    for (int i = n - 1; i >= 0; --i) {
      int val = input[i];
      if (st.empty()) {
        st.push(i);
      } else {
        while (!st.empty() and input[st.top()] < val) {
          int index = st.top();
          st.pop();
          next_greater[index] = i;
        }
        st.push(i);
      }
    }
    int hops = 0;
    int index = n - 1;
    while (next_greater[index] != -1) {
      ++hops;
      index = next_greater[index];
    }
    cout << hops << endl;
  }
}
