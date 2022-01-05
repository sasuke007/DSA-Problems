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
vector<int> required_elements(set<int> &eleemnts, int n) {
  vector<int> required;
  for (int i = 1; i <= n; ++i) {
    if (eleemnts.find(i) == eleemnts.end()) {
      required.push_back(i);
    }
  }
  return required;
}
vector<int> to_change(vector<int> &input) {
  int n = input.size();
  set<int> present;
  vector<int> change;
  for (int i = 0; i < n; ++i) {
    if (input[i] >= 1 and input[i] <= n and
        present.find(input[i]) == present.end()) {
          present.insert(input[i]);
    }
    else{
      change.push_back(input[i]);
    }
  }
  return change;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef D_DEBUG
  freopen("input.txt", "r", stdin)
#endif
      int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> input(n);
    set<int> present;
    for (int i = 0; i < n; ++i) {
      cin >> input[i];
      present.insert(input[i]);
    }
    vector<int> change = to_change(input);
    vector<int> require = required_elements(present,n);
    sort(change.begin(),change.end());
    sort(require.begin(),require.end());
    int answer = change.size();
    for(int i=0;i<change.size();++i){
      int val=change[i];
      val-=require[i];
      if(val <=  require[i]){
        answer=-1;
        break;
      }
    }
    cout<<answer<<endl;
  }
}
