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
        int n;
        cin>>n;
        vector<int> input(n);
        for(int i=0;i<n;++i){
            cin>>input[i];
        }
        string color;
        cin>>color;
        vector<int> blue,red;
        for(int i=0;i<n;++i){
            if(color[i]=='B'){
                blue.push_back(input[i]);
            }
            else{
                red.push_back(input[i]);
            }
        }
        sort(blue.begin(),blue.end());
        sort(red.begin(),red.end());
        int curr_color=1;
        int possible = true;
        for(int i=0;i<blue.size();++i){
            if(blue[i]<curr_color){
                possible=false;
            }
            ++curr_color;
        }
        for(int i=0;i<red.size();++i){
            if(red[i]>curr_color){
                possible=false;
            }
            ++curr_color;
        }
        cout<<(possible?"YES":"NO")<<endl;
    }
}