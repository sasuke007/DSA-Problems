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
void compute_heights(vector<vector<int> > &input) {
  int n = input.size();
  int m = input[0].size();
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (input[i][j] != 0) {
        input[i][j] += input[i - 1][j];
      }
    }
  }
}
vector<int> first_smaller_element_left(vector<vector<int> > &input, int row) {
  int n = input[0].size();
  vector<int> next_smaller(n);
  next_smaller[0] = -1;
  stack<pii> elements;
  elements.push({input[row][0], 0});
  for (int i = 1; i < n; ++i) {
    while (!elements.empty() and elements.top().first >= input[row][i]) {
      elements.pop();
    }
    next_smaller[i] = (elements.empty() ? -1 : elements.top().second);
    elements.push({input[row][i], i});
  }
  return next_smaller;
}
vector<int> first_smaller_element_right(vector<vector<int> > &input, int row) {
  int n = input[0].size();
  stack<pii> elements;
  vector<int> next_smaller(n);
  elements.push({input[row][n - 1], n - 1});
  next_smaller[n - 1] = n;
  for (int i = n - 2; i >= 0; --i) {
    while (!elements.empty() and elements.top().first >= input[row][i]) {
      elements.pop();
    }
    next_smaller[i] = (elements.empty() ? n : elements.top().second);
    elements.push({input[row][i], i});
  }
  return next_smaller;
}
int largest_area_histogram(vector<vector<int> > &input, int row) {
  int area = 0;
  int n = input[0].size();
  vector<int> left_smaller = first_smaller_element_left(input, row);
  vector<int> right_smaller = first_smaller_element_right(input, row);
  for (int i = 0; i < n; ++i) {
    area = max(area, input[row][i] * (right_smaller[i] - left_smaller[i] - 1));
  }
  return area;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef _DEBUG
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
  compute_heights(input);
  int max_area = 0;
  for (int i = 0; i < n; ++i) {
    max_area = max(max_area, largest_area_histogram(input, i));
  }
  cout << max_area << endl;
}