#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
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

void solve() {
  int n;
  cin >> n;
  vector<int> input(n);
  string ratings;
  for (int i = 0; i < n; ++i) {
    cin >> input[i];
  }
  cin >> ratings;
  vector<int> dislike_songs, liked_songs;
  for (int i = 0; i < n; ++i) {
    if (ratings[i] == '1') {
      liked_songs.push_back(input[i]);
    } else {
      dislike_songs.push_back(input[i]);
    }
  }
  sort(liked_songs.begin(), liked_songs.end());
  sort(dislike_songs.begin(), dislike_songs.end());
  vector<int> answer(n + 1, 0);
  int count = 1;
  for (int i = 0; i < dislike_songs.size(); ++i) {
    answer[dislike_songs[i]] = count++;
  }
  for (int i = 0; i < liked_songs.size(); ++i) {
    answer[liked_songs[i]] = count++;
  }
  for (int i = 0; i < n; ++i) {
    cout << answer[input[i]] << " ";
  }
  cout << endl;
}
int main() {
  fast_cin();
  ll t;
  cin >> t;
  for (int it = 1; it <= t; it++) {
    solve();
  }
}