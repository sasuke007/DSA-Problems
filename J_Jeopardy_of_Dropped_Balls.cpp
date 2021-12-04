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
int get_column(vector<vector<int> >& board, int initial_column) {
  int n = board.size();
  int m = board[0].size();
  int initial_row=0;
  while(initial_row < n) {
      if(board[initial_row][initial_column]==1){
          board[initial_row][initial_column]=2;
          initial_column++;
      }
      else if(board[initial_row][initial_column]==2){
          board[initial_row][initial_column]=2;
          initial_row++;
      }
      else{
          board[initial_row][initial_column]=2;
          initial_column--;
      }
  }
  return initial_column+1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef D_DEBUG
  freopen("input.txt", "r", stdin)
#endif
      int n,
      m, k;
  cin >> n >> m >> k;
  vector<vector<int> > board(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> board[i][j];
    }
  }
  for (int i = 0; i < k; ++i) {
    int col;
    cin >> col;
    col--;
    cout << get_column(board, col) << " ";
  }
  cout << endl;
}
