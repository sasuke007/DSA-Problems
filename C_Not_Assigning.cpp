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
vector<int> primes() {
  int n = 1e4;
  vector<int> primes;
  for (int i = 2; i < n; ++i) {
    bool isPrime = true;
    for (int j = 2; j < i; ++j) {
      if (i % j == 0) {
        isPrime = false;
        break;
      }
    }
    if (isPrime) {
      primes.push_back(i);
    }
  }
  return primes;
}
int get_next_prime(int &curr_prime) {
  curr_prime = (curr_prime == 2 ? 3 : 2);
  return curr_prime;
}
void dfs(vector<vector<int> > &tree, map<pair<int, int>, int> &weights,
         vector<bool> &visited, int &prime, int root) {
  visited[root] = true;
  for (int i = 0; i < tree[root].size(); ++i) {
    int child = tree[root][i];
    if (!visited[child]) {
      int curr_prime = get_next_prime(prime);
      weights[{root, child}] = curr_prime;
      weights[{child, root}] = curr_prime;
      dfs(tree, weights, visited, prime, child);
    }
  }
}
void solve() {
  int vertices;
  cin >> vertices;
  vector<pair<int, int> > edges;
  vector<vector<int> > tree(vertices + 1, vector<int>());
  vector<bool> visited(vertices + 1, false);
  for (int i = 0; i < vertices - 1; ++i) {
    int u, v;
    cin >> u >> v;
    edges.push_back({u, v});
    tree[u].push_back(v);
    tree[v].push_back(u);
  }
  map<pair<int, int>, int> weights;
  int root = 1, parent = -1, prime = 2;
  int possible = true;
  for (int i = 0; i <= vertices; ++i) {
    if (tree[i].size() > 2) {
      possible = false;
    }
    if (tree[i].size() == 1) {
      root = i;
    }
  }
  if (!possible) {
    cout << -1 << endl;
    return;
  }
  //cout << root << endl;
  dfs(tree, weights, visited, prime, root);
  for (int i = 0; i < edges.size(); ++i) {
    cout << weights[edges[i]] << " ";
  }
  cout << endl;
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