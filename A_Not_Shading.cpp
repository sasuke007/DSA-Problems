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

void solve() {
    int n,m,r,c;
    cin>>n>>m>>r>>c;
    vector<string> input(n);
    int black_cells = 0;
    for(int i=0;i<n;++i){
        cin>>input[i];
        for(int j=0;j<m;++j){
            if(input[i][j]=='B'){
                ++black_cells;
            }
        }
    }
    if(black_cells==0){
        cout<<-1<<endl;
        return ;
    }
    if(input[r-1][c-1]=='B'){
        cout<<0<<endl;
        return ;
    }
    int black_cell_in_row_col = 0;
    for(int i=0;i<m;++i){
        if(input[r-1][i]=='B'){
            ++black_cell_in_row_col;
        }
    }
    for(int i=0;i<n;++i){
        if(input[i][c-1]=='B'){
            ++black_cell_in_row_col;
        }
    }
    if(black_cell_in_row_col>0){
        cout<<1<<endl;
        return ;
    }
    cout<<2<<endl;
    
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