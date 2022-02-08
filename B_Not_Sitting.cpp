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

int get_max_distance(int r, int c, int n, int m) {
  int top_left = abs(r) + abs(c);
  int bottom_left = abs(r - n) + abs(c);
  int top_right = abs(r) + abs(m - c);
  int botton_right = abs(n - r) + abs(m - c);
  return max(top_left, max(bottom_left, max(top_right, botton_right)));
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> distance;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      distance.push_back(get_max_distance(i, j, n - 1, m - 1));
    }
  }
  sort(distance.begin(), distance.end());
  for(int i=0;i<distance.size();++i){
      cout<<distance[i]<<" ";
  }
  cout<<endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
}