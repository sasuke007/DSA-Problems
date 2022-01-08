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

bool valid(int i, int j, vector<vector<int> > &A, vector<vector<int> > &look) {
  int n = look.size();
  int m = look[0].size();
  if (i >= 0 and i < n and j >= 0 and j < m and look[i][j] == 0 and
      A[i][j] == 0) {
    return true;
  }
  return false;
}
void bfs(vector<vector<int> > &A, vector<vector<int> > &distance,
         vector<vector<int> > &visited, int i, int j) {
  int n = A.size();
  int m = A[0].size();
  vector<vector<int> > look(n, vector<int>(m, 0));
  vector<vector<int> > temp_distance(n,vector<int>(m,0));
  queue<pair<int, int> > nodes;
  look[i][j] = 1;
  nodes.push({i, j});
  vector<int> dx = {1, 0, -1, 0};
  vector<int> dy = {0, 1, 0, -1};
  while (!nodes.empty()) {
    pair<int, int> node = nodes.front();
    nodes.pop();
    for (int i = 0; i < 4; ++i) {
      if (valid(node.first + dx[i], node.second + dy[i], A, look)) {
        ++visited[node.first + dx[i]][node.second + dy[i]];
        ++look[node.first + dx[i]][node.second + dy[i]];
        temp_distance[node.first + dx[i]][node.second + dy[i]] +=
            temp_distance[node.first][node.second] + 1;
        nodes.push({node.first + dx[i], node.second + dy[i]});
      }
    }
  }
  for(int i=0;i<n;++i){
      for(int j=0;j<m;++j){
          distance[i][j]+=temp_distance[i][j];
      }
  }
}
int solve(vector<vector<int> > &A) {
  int n = A.size();
  int m = A[0].size();
  vector<vector<int> > visited(n, vector<int>(m, 0)),
      distance(n, vector<int>(m, 0));
  int total_buildings = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (A[i][j] == 1) {
        ++total_buildings;
        bfs(A, distance, visited, i, j);
      }
    }
  }
  int inf = 1e9 + 7;
  int min_distance = inf;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (visited[i][j] == total_buildings) {
        min_distance = min(min_distance, distance[i][j]);
      }
    }
  }
  return (min_distance == inf ? -1 : min_distance);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef D_DEBUG
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  vector<vector<int> > input(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> input[i][j];
    }
  }
  cout << solve(input) << endl;
}