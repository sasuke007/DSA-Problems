#include <math.h>

#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>
using namespace std;
#define endl "\n"
typedef long long ll;
set<int> get_primes() {
  set<int> primes;
  int n = 1e6 + 7;
  vector<int> seive(n, 1);
  for (int i = 2; i < n; ++i) {
    if (seive[i] == 1) {
      for (int j = 2 * i; j < n; j += i) {
        seive[j] = 0;
      }
    }
  }
  for (int i = 2; i < n; ++i) {
    if (seive[i] == 1) {
      primes.insert(i);
    }
  }
  return primes;
}
ll find_pairs(vector<int> &input, vector<int> &visited, set<int> &primes, int e,
              int pos) {
  ll answer = 0;
  int start = pos - e;
  int n = input.size();
  vector<int> primes_locations;
  primes_locations.push_back(start);
  while (pos < n) {
    visited[pos] = 1;
    if (input[pos] != 1 and primes.find(input[pos]) == primes.end()) {
      break;
    }
    if (primes.find(input[pos]) != primes.end()) {
      primes_locations.push_back(pos);
    }
    pos += e;
  }
  primes_locations.push_back(pos);
  for (int i = 1; i < primes_locations.size() - 1; ++i) {
    int location = primes_locations[i];
    ll prev = (location - primes_locations[i - 1]) / e -1 ;
    ll next = (primes_locations[i + 1] - location ) / e - 1;
    answer += next + (next * 1ll * prev) + prev;
  }
  return answer;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
#endif
  int tc;
  cin >> tc;
  set<int> primes = get_primes();
  while (tc--) {
    int n, e;
    cin >> n >> e;
    vector<int> input(n);
    for (int i = 0; i < n; ++i) {
      cin >> input[i];
    }
    vector<int> visited(n, 0);
    ll answer = 0;
    for (int i = 0; i < n; ++i) {
      if (visited[i] == 0) {
        answer += find_pairs(input, visited, primes, e, i);
      }
    }
    cout << answer << endl;
  }
}