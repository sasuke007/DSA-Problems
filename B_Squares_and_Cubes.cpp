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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef D_DEBUG
  freopen("input.txt", "r", stdin)
#endif
    int tc;
    cin>>tc;
    
    while(tc--){
        ll n;
        cin>>n;
        ll root = ceil(sqrt(n));
        ll count =1;
        set<ll> present;
        for(ll i=2;i<=root;++i){
            ll square = i*i;
            ll cube = i*i*i;
            if(present.find(square)==present.end() and square<=n){
                ++count;
                present.insert(square);
            }
            if(present.find(cube)==present.end() and cube<=n){
                ++count;
                present.insert(cube);
            }
        }
        cout<<count<<endl;
    }
}