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
  freopen("input.txt", "r", stdin);
#endif
  int tc;
  cin >> tc;
  while (tc--) {
    ll n, k, x;
    cin >> n >> k >> x;
    string input;
    cin >> input;
    x--;
    reverse(input.begin(), input.end());
    string answer;
    for (int i = 0; i < n; ++i) {
      char val = input[i];
      if (val == 'a') {
        answer += 'a';
      } else {
        int j = i;
        int count = 0;
        while (j < n and input[j] == input[i]) {
          ++count;
          ++j;
        }
        i = j - 1;
        ll add_b = x % (count * k + 1);
        for (ll k = 0; k < add_b; ++k) {
          answer += 'b';
        }
        x /= (count * k + 1);
      }
    }
    reverse(answer.begin(),answer.end());
    cout<<answer<<endl;
  }
}