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
int mod = 998244353;
ll power(ll base, ll exp) {
  if (exp == 0) {
    return 1;
  }
  if (exp == 1) {
    return base;
  }
  ll num = power(base, num / 2);
  num = (num * 1ll * num) % mod;
  if (exp & 1) {
    num = (num * 1ll * base) % mod;
  }
  return num;
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
    int n;
    cin >> n;
    int minus_one = 0, zero = 0, one = 0, two = 0;
    for (int i = 0; i < n; ++i) {
      int val;
      cin >> val;
      if (val == -1) {
        minus_one++;
      } else if (val == 0) {
        zero++;
      } else if (val == 1) {
        one++;
      } else if (val == 2) {
        two++;
      }
    }
    ll answer = 0;
    answer = (answer + (power(2, zero) - 1)) % mod;
    answer = (answer + (power(2, one) - 1)) % mod;
    answer = (answer + (power(2, minus_one) - 1)) % mod;
    answer =
        (answer + ((power(2, zero) - 1) % mod * (power(2, two) - 1) % mod)) %
        mod;
    answer = (answer +
              ((power(2, minus_one) - 1) % mod * (power(2, one) - 1) % mod)) %
             mod;
    answer = (answer + ((power(2, zero) - 1) % mod * (power(2, one) - 1) % mod))%mod;
    cout << answer << endl;
  }
}