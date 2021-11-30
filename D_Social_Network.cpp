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
int find(vector<int> &connections, int u) {
  while (connections[u] > 0) {
    u = connections[u];
  }
  return u;
}
int get_highest(vi &connections) {
  int index = -1;
  int highest = INT_MIN;
  for (int i = 1; i < connections.size(); ++i) {
    if (connections[i] < 0) {
      if (abs(connections[i]) > highest) {
        highest = abs(connections[i]);
        index = i;
      }
    }
  }
  return index;
}
int get_second_highest(vi &connections, int highest_index) {
  int index = -1;
  int second_highest = -1;
  int n = connections.size();
  for (int i = 1; i < n; ++i) {
    if (connections[i] < 0) {
      if (i == highest_index) {
        continue;
      }
      if (abs(connections[i]) > second_highest and
          abs(connections[i]) <= abs(connections[highest_index])) {
        second_highest = abs(connections[i]);
        index = i;
      }
    }
  }
  return index;
}

int get_sum(vi &connections, int extra_edges) {
  vector<int> temp(connections);
  sort(temp.begin(), temp.end());
  int sum = 0;
  ++extra_edges;
  for (int i = 0; i < temp.size() and extra_edges > 0; --extra_edges, ++i) {
    if (temp[i] < 0) {
      sum += abs(temp[i]);
    }
  }
  return sum;
}
int get_connections(vector<int> &connections, int u, int v, int &extra_edges) {
  int u_parent = find(connections, u);
  int v_parent = find(connections, v);
  if (u_parent != v_parent) {
    if (abs(connections[u_parent]) >= abs(connections[v_parent])) {
      connections[u_parent] += connections[v_parent];
      connections[v_parent] = u_parent;
      if (extra_edges == 0) {
        return abs(connections[u_parent]);
      }
    } else {
      connections[v_parent] += connections[u_parent];
      connections[u_parent] = v_parent;
      if (extra_edges == 0) {
        return abs(connections[v_parent]);
      }
    }
  }
  if (u_parent == v_parent) ++extra_edges;
  return get_sum(connections, extra_edges);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef D_DEBUG
  freopen("input.txt", "r", stdin)
#endif
      int n,
      d;
  cin >> n >> d;
  vector<int> connections(n + 1, -1);
  int max_connections = 1;
  int extra_edges = 0;
  for (int i = 0; i < d; ++i) {
    int u, v;
    cin >> u >> v;
    int curr_connections = get_connections(connections, u, v, extra_edges);
    max_connections = max(max_connections, curr_connections);
    cout << max_connections - 1 << endl;
  }
}