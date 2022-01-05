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
void solve() {
  int n;
  cin >> n;
  int root;
  vector<int> tree(n);
  for (int i = 0; i < n; ++i) {
    cin >> tree[i];
    if (tree[i] == (i + 1)) {
      root = i+1;
    }
  }
  vector<int> permutation(n);
  for (int i = 0; i < n; ++i) {
    cin >> permutation[i];
  }
  if (permutation[0] != root) {
    cout << -1 << endl;
    return;
  }
  vector<int> distance(n+1, -1);
  distance[permutation[0]] = 0;
  for (int i = 1; i < n; ++i) {
    int node = permutation[i];
    if (distance[tree[node-1]] == -1) {
      cout << -1 << endl;
      return;
    }
    distance[permutation[i]]=distance[permutation[i-1]]+1;
  }
  for(int i=0;i<n;++i){
      cout<<distance[i+1] -distance[tree[i]]<<" ";
  }
  cout<<endl;
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
    solve();
  }
}
