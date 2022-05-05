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
int get_length(int n) {
  int len = 0;
  while (n) {
    ++len;
    n /= 10;
  }
  return len;
}
vector<char> get_number(int n) {
  vector<char> num;
  while (n) {
    int rem = n % 10;
    n /= 10;
    num.push_back(rem + 48);
  }
  reverse(num.begin(), num.end());
  return num;
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
    int x1, p1;
    int x2, p2;
    cin >> x1 >> p1 >> x2 >> p2;
    int x1_len = get_length(x1);
    int x2_len = get_length(x2);
    if (x1_len + p1 > x2_len + p2) {
      cout << ">" << endl;
    } else if (x2_len + p2 > x1_len + p1) {
      cout << "<" << endl;
    } else {
      vector<char> x1_num = get_number(x1);
      vector<char> x2_num = get_number(x2);
      if (x1_num.size() > x2_num.size()) {
        int diff = x1_num.size() - x2_num.size();
        int count = 0;
        while (count < p2 and diff > 0) {
          x2_num.push_back(48);
          ++count;
          --diff;
        }
      } else if (x2_num.size() > x1_num.size()) {
        int diff = x2_num.size() - x1_num.size();
        int count = 0;
        while (count < p1 and diff > 0) {
          x1_num.push_back(48);
          ++count;
          --diff;
        }
      }
      if (x1_num > x2_num) {
        cout << ">" << endl;
      } else if (x2_num > x1_num) {
        cout << "<" << endl;
      } else {
        cout << "=" << endl;
      }
    }
  }
}
