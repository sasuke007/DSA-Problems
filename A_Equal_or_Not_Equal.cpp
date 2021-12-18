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
        string s;
        cin>>s;
        int n= s.size();
        vector<int> input(n);
        int number = 1;
        if(s[n-1]=='N'){
            input[0] = number;
            ++number;
            input[n-1]=number;
            ++number;
        }
        else{
            input[0]=input[n-1]=number;
            ++number;
        }
        for(int i=0;i<n-2;++i){
            if(s[i]=='E'){
                input[i+1]=input[i];
            }
            else{
                input[i+1]=number;
                ++number;
            }
        }
        string ans = "NO";
        if(s[n-2]=='E' and input[n-1] == input[n-2]){
            ans="YES";
        }

        if(s[n-2]=='N' and input[n-1] != input[n-2]){
            ans = "YES";
        }
        cout<<ans<<endl;
    }
}
