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
int length(ll n) {
  int count = 0;
  while (n) {
    ++count;
    n /= 10;
  }
  return count;
}
int get_last_digit(ll &n) {
  int last_digit = n % 10;
  n /= 10;
  return last_digit;
}
bool add(ll a, ll b, ll c) {
  int exp = 0;
  string number;
  while (a or b) {
    int a_last_digit = get_last_digit(a);
    int b_last_digit = get_last_digit(b);
    number = to_string(a_last_digit + b_last_digit) + number;
  }
  if (to_string(c) == number) {
    return true;
  }
  return false;
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
    ll a, c, x, y, z;
    cin >> x >> z;
    a = x, c = z;
    ll len = length(c);
    ll curr = 0;
    ll exp = 0;
    ll b = 0;
    string number;
    while (curr < len) {
      int a_last_digit = get_last_digit(a);
      int c_last_digit = get_last_digit(c);
      ++curr;
      if (c_last_digit - a_last_digit < 0) {
        if (curr >= len) {
          b = -1;
          break;
        }
        int temp = get_last_digit(c);
        ++curr;
        c_last_digit += temp * 10;
      }
      ll b_last_digit = c_last_digit - a_last_digit;
      if (b_last_digit >= 10 or b_last_digit < 0) {
        b = -1;
        break;
      }
      b += b_last_digit * pow(10, exp);
      //number = to_string(b_last_digit) + number;
      ++exp;
    }
    y = b;
    if (a != 0) {
      b = -1;
    }
    cout<<b<<endl;
  }
}