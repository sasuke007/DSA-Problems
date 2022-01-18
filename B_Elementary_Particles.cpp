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
    int n;
    cin>>n;
    unordered_map<int,vector<int> > pos;
    for(int i=0;i<n;++i){
        int elem;
        cin>>elem;
        pos[elem].push_back(i);
    }
    int answer = -1;
    for(auto it=pos.begin();it!=pos.end();++it){
        int len = it->second.size();
        for(int i=0;i<len-1;++i){
            answer = max(answer,n-(it->second[i+1] - it->second[i]));
        }
    }
    cout<<answer<<endl;
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