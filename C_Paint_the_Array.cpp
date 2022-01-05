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
ll gcd(ll a,ll b){
    if(a==0){
        return b;
    }
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
ll check_odd_positions(vector<ll> &input) {
  int n = input.size();
  ll hcf = 0;
  for (int i = 0; i < n; i += 2) {
    hcf = gcd(hcf, input[i]);
  }
  for (int i = 1; i < n; i += 2) {
    if (input[i] % hcf == 0) {
      return 0;
    }
  }
  return hcf;
}
ll check_even_positions(vector<ll> &input) {
  int n = input.size();
  ll hcf = 0;
  for (int i = 1; i < n; i += 2) {
    hcf =gcd(hcf, input[i]);
  }
  for (int i = 0; i < n; i += 2) {
    if (input[i] % hcf == 0) {
      return 0;
    }
  }
  return hcf;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef D_DEBUG
  freopen("input.txt", "r", stdin);
#endif
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<ll> input(n);
    for (int i = 0; i < n; ++i) {
      cin >> input[i];
    }
    ll answer = 0;
    answer = max(check_odd_positions(input), check_even_positions(input));
    cout << answer << endl;
  }
}