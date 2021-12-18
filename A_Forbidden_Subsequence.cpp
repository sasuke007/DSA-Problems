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
        string s,t;
        cin>>s>>t;
        unordered_map<char,int> freq;
        for(int i=0;i<s.size();++i){
            freq[s[i]]++;
        }
        if(freq['a']==0 or freq['b']==0 or freq['c']==0){
            sort(s.begin(),s.end());
            cout<<s<<endl;
        }
        else if(t=="abc"){
            for(char i='a';i<='z';++i){
                if(i=='b'){
                    for(int j=0;j<freq['c'];++j){
                        cout<<'c';
                    }
                }
                else if(i=='c'){
                    for(int j=0;j<freq['b'];++j){
                        cout<<'b';
                    }
                }
                else{
                    for(int j=0;j<freq[i];++j){
                        cout<<i;
                    }
                }
            }
            cout<<endl;
        }
        else{
            sort(s.begin(),s.end());
            cout<<s<<endl;
        }
    }
}