#include <bits/stdc++.h>

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

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
#define fast_cin()                  \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define endl "\n"
#define debug(x) cout << #x << " " << x << endl;
string solve() {
  int a, b, c;
  cin >> a >> b >> c;
  int d = b - a;
  if ((a + 2 * d) > 0 and (a + 2 * d) % c == 0) {
    return "YES";
  }
  d = c - b;
  if ((c - 2 * d) > 0 and (c - 2 * d) % a == 0) {
    return "YES";
  }
  if ((c - a) % 2 != 0) {
    return "NO";
  }
  d = (c - a) / 2;
  if(a+d > 0 and (a+d)%b==0){
      return "YES";
  }
  return "NO";
}
int main() {
  fast_cin();
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ll t;
  cin >> t;
  for (int it = 1; it <= t; it++) {
    cout << solve() << endl;
  }
}