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
int solve(string &input, char c) {
  int start = 0;
  int end = input.size() - 1;
  int answer = 1e9 + 7;
  int possible = true;
  int operations = 0;
  while (start <= end) {
    if (input[start] == input[end]) {
      ++start, --end;
    } else if (input[start] == c) {
      ++start;
      ++operations;
    } else if (input[end] == c) {
      --end;
      ++operations;
    } else {
      possible = false;
      break;
    }
  }
  if (possible) {
    answer = operations;
  }
  return answer;
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
    string input;
    cin >> input;
    int inf = 1e9 + 7;
    int min_operations = inf;
    int start = 0;
    int end = input.size() - 1;
    bool is_palindrome = true;
    while (start <= end) {
      if (input[start] == input[end]) {
        ++start, --end;
      } else {
        min_operations = min(min_operations, min(solve(input, input[start]),
                                                 solve(input, input[end])));
        is_palindrome = false;
        break;
      }
    }
    if (is_palindrome) {
      cout << 0 << endl;
    } else {
      cout << ((min_operations == inf) ? -1 : min_operations) << endl;
    }
  }
}