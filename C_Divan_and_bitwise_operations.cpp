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
ll power(int base, int exp, int mod) {
  if (exp == 0) {
    return 1;
  }
  if (exp == 1) {
    return base;
  }
  ll multiply = power(base, exp / 2, mod);
  multiply = (multiply * multiply) % mod;
  if(exp&1){
    multiply = (multiply*base)%mod;
  }
  return multiply;
}
void solve() {
  int n, m;
  cin >> n >> m;
  int mod = 1e9 + 7;
  int bitwise_xor = 0;
  for (int i = 0; i < m; ++i) {
    int l, r, elem;
    cin >> l >> r >> elem;
    //cout<<"elem "<<elem<<endl;
    bitwise_xor |= elem;
  }
 // cout<<"xor "<<bitwise_xor<<endl;
  //cout<<"power "<<power(2,n-1,mod)<<endl;
  cout << (bitwise_xor * power(2, n - 1, mod))%mod<<endl;
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