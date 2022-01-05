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
  // #ifdef D_DEBUG
  //   freopen("input.txt", "r", stdin);
  // #endif
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<string> input(n);
    for (int i = 0; i < n - 2; ++i) {
      cin >> input[i];
    }
    string answer;
    answer += input[0][0];
    bool added = false;
    // cout << answer << endl;
    for (int i = 1; i < n - 2; ++i) {
      if (input[i][0] == input[i - 1][1]) {
        answer += input[i][0];
      } else {
        added = true;
        answer += input[i - 1][1];
        answer += input[i][0];
      }
    }
    answer += input[n - 3][1];
    if (!added) {
        answer+='a';
    }
    cout << answer << endl;
  }
}