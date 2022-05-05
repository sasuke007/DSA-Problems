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
ll power(ll base,ll exp,ll mod){
    if(exp==0){
        return 1;
    }
    if(exp==1){
        return base;
    }
    ll temp = power(base,exp/2,mod);
    temp = (temp*temp)%mod;
    if(exp&1){
        temp=(temp*base)%mod;
    }
    return temp;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef D_DEBUG
  freopen("input.txt", "r", stdin)
#endif
    int tc;
    cin>>tc;
    while(tc--){
        int n,k;
        cin>>n>>k;
        int mod = 1e9+7;
        ll answer =0;
        for(int i=0;i<32;++i){
            if(k&(1<<i)){
                answer=(answer+power(n,i,mod))%mod;
            }
        }
        cout<<answer<<endl;
    }
}