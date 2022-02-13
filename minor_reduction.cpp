
#include <bits/stdc++.h> 
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 
void remove_leading_zeroes(string &sum){
    int n = sum.size();
    int i=0;
    while(sum[i]=='0'){
        ++i;
    }
    sum.erase(0,i);
    if(sum==""){
        sum="0";
    }
}
string get_sum_string(string str,int index){
        string substring = str.substr(index,2);
        int int_sum = (substring[0]-48)+(substring[1]-48);
        string sum = to_string(int_sum);
        str.erase(index,2);
        str.insert(index,sum);
        remove_leading_zeroes(str);
        return str;
}
bool comparator(string &a,string &b){
    if(a==b){
        return true;
    }
    bool temp;
    temp=false;
    if((int)a.size() == (int)b.size()){
        return a<b;
    }
    return a.size()<b.size();
}
void solve(){
    string input;
    cin>>input;
    int n=input.size();
    vector<int> numbers(n);
    for(int i=0;i<n;++i){
        numbers[i]=input[i]-48;
    }
    bool changed =false;
    for(int i=n-2;i>=0;--i){
        int sum =numbers[i]+numbers[i+1];
        if(sum >= 10){
            numbers[i+1]=sum%10;
            numbers[i]=sum/10;
            changed=true;
            break;
        }
    }
    if(!changed){
        int sum=numbers[0]+numbers[1];
        numbers[0]=sum/10;
        numbers[1]=sum%10;
    }
    vector<int> answer;
    int zero =0;
    while(numbers[zero]==0){
        ++zero;
    }
    numbers.erase(numbers.begin(),numbers.begin()+zero);
    if(numbers.empty()){
        numbers.push_back(0);
    }
    for(int i=0;i<numbers.size();++i){
        cout<<numbers[i];
    }
    cout<<endl;
}
int main()
{
 fast_cin();
 ll t;
 cin >> t;
 for(int it=1;it<=t;it++) {
    solve();
 }
 return 0;
}