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

typedef vector<ll> v64;
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
  unordered_map<int, int> freq;
  vector<int> input(n);
  for (int i = 0; i < n; ++i) {
    int elem;
    cin >> elem;
    freq[elem]++;
    input[i] = elem;
  }
  int answer = 0;
  bool zero_present = false;
  for(auto it=freq.begin();it!=freq.end();++it){
      int elem = it->first;
      int val = it->second;
      //cout<<elem<<" "<< val<<endl;
      if(val==0){
          continue;
      }
      if(elem==0){
          zero_present=true;
      }
      else if(val==1){
          ++answer;
      }
      else{
          if(freq[-1*elem]>0){
              ++answer;
          }
          else{
              answer+=2;
          }
      }
  }
  cout << answer + zero_present << endl;
}
int main() {
  fast_cin();
  ll t;
  cin >> t;
  for (int it = 1; it <= t; it++) {
    solve();
  }
=======
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
#ifdef D_DEBUG
  freopen("input.txt", "r", stdin)
#endif
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        unordered_map<int,int> freq;
        for(int i=0;i<n;++i){
            int val;
            cin>>val;
            freq[abs(val)]++;
        }
        int answer =0;
        for(auto it=freq.begin();it!=freq.end();++it){
            ++answer;
            if(it->first!=0 and it->second>1){
                ++answer;
            }
        }
        cout<<answer<<endl;
    }
>>>>>>> e9e8ffe (codeforces questions)
}