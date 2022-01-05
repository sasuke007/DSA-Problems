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
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
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
        string input;
        cin>>input;
        bool two_characters = false;
        char first_character = input[0];
        int i=1;
        while(i<n and input[i-1]>=input[i]){
            if(input[i]!=first_character){
                two_characters=true;
            }
            ++i;
        }
        if(n==1){
            cout<<first_character<<first_character<<endl;
        }
        else if(input[1]==first_character){
            cout<<first_character<<first_character<<endl;
        }
        else{
            string lexicographically_smallest_string = input.substr(0,i);
            cout<<lexicographically_smallest_string;
            reverse(lexicographically_smallest_string.begin(),lexicographically_smallest_string.end());
            cout<<lexicographically_smallest_string<<endl;
        }
    }
}