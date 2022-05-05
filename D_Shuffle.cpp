#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
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
v64 factorial(5010, 1);
v64 inverse_factorial(5010, 1);
const int mod = 998244353;
ll power(int base, int exp) {
  if (exp == 0) return 1;
  if (exp == 1) return base;
  ll temp = power(base, exp / 2);
  temp = (temp * temp) % mod;
  if (exp & 1) {
    temp = (temp * base) % mod;
  }
  return temp;
}
void precompute() {
  for (int i = 2; i < 5010; ++i) {
    factorial[i] = (factorial[i - 1] * 1ll * i) % mod;
    inverse_factorial[i] =
        (inverse_factorial[i - 1] * 1ll * power(i, mod - 2)) % mod;
  }
}
int binomial(int n, int k) {
  return (factorial[n] * inverse_factorial[k] * inverse_factorial[n - k]) % mod;
}
void solve() {
    
}
int main() {
  fast_cin();
  ll t;
  cin >> t;
  precompute();
  for (int it = 1; it <= t; it++) {
    solve();
  }
}