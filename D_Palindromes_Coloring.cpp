#include <bits/stdc++.h>

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

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
#define fast_cin()                  \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define endl "\n"
#define debug(x) cout << #x << " " << x << endl;

bool check(int single_characters, int double_characters, int mid, int k) {
  double_characters -= ((mid / 2) * k);
if(double_characters<0){
      return false;
  }
  single_characters+=2*double_characters;
  single_characters -= ((mid % 2) * k);
  
  if (single_characters < 0) {
    return false;
  }
  return true;
}
void solve() {
  int n, k;
  cin >> n >> k;
  string input;
  cin >> input;
  unordered_map<char, int> freq;
  int single_characters = 0;
  int double_characters = 0;
  for (int i = 0; i < n; ++i) {
    char letter = input[i];
    freq[letter]++;
  }
  for (auto it = freq.begin(); it != freq.end(); ++it) {
    if (it->second & 1) {
      single_characters++;
    }
    double_characters += (it->second / 2);
  }
  int low = 1, high = n;
  int answer = 1;
  //cout<<single_characters<<" "<<double_characters<<endl;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (check(single_characters, double_characters, mid, k)) {
      low = mid + 1;
      answer = max(answer, mid);
    } else {
      high = mid - 1;
    }
  }
  cout << answer << endl;
}
int main() {
  fast_cin();
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ll t;
  cin >> t;
  for (int it = 1; it <= t; it++) {
    solve();
  }
}