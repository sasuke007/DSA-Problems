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
  int n, l;
  cin >> n >> l;
  vector<int> input(n);
  for (int i = 0; i < n; ++i) {
    cin >> input[i];
  }
  int answer =0;
  for (int i = 0; i < 32; ++i) {
    int ones = 0, zeros = 0;
    for (int j = 0; j < n; ++j) {
      if ((input[j] & (1 << i)) != 0)
        ++ones;
      else
        ++zeros;
    }
    if(ones>zeros){
        answer|=(1<<i);
    }
  }
  cout<<answer<<endl;
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