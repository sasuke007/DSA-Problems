#include <iostream>
#include <unordered_map>
#include <map>
#include<vector>
#include<numeric>
#include <algorithm>
#include<list>
#include<queue>
#include <unordered_set>
#include <cmath>
#include <stack>
#include<set>
#include<stdio.h>

using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) { cerr << t; }

void _print(int t) { cerr << t; }

void _print(string t) { cerr << t; }

void _print(char t) { cerr << t; }

void _print(lld t) { cerr << t; }

void _print(double t) { cerr << t; }

void _print(ull t) { cerr << t; }

template<class T, class V>
void _print(pair<T, V> p) {
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}

template<class T>
void _print(vector<T> v) {
    cerr << "[ ";
    for (T i: v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]\n";
}

template<class T>
void _print(set<T> v) {
    cerr << "[ ";
    for (T i: v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

template<class T>
void _print(multiset<T> v) {
    cerr << "[ ";
    for (T i: v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

template<class T, class V>
void _print(map<T, V> v) {
    cerr << "[ ";
    for (auto i: v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}


double knightProbability(int n, int k, int row, int column) {
    if (k == 0) {
        return 1.0;
    }
    vector<vector<vector<double> > > dp(k, vector<vector<double> >(n, vector<double>(n, 0)));
    vector<pair<int, int> > knightMoves{
            {1,  2},
            {2,  1},
            {-1, 2},
            {-2, 1},
            {-1, -2},
            {-2, -1},
            {1,  -2},
            {2,  -1}
    };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            double totalMoves = 8;
            double insideMoves = 0;
            for (pair<int, int> move: knightMoves) {
                int destinedX = i - move.first;
                int destinedY = j - move.second;
                if (destinedX < n and destinedX >= 0 and destinedY >= 0 and destinedY < n) {
                    ++insideMoves;
                }
                dp[0][i][j] = insideMoves / totalMoves;
            }
        }
    }
    for (int x = 1; x < k; ++x) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                double insideProbability = 0;
                for (pair<int, int> move: knightMoves) {
                    int destinedX = i - move.first;
                    int destinedY = j - move.second;
                    if (destinedX < n and destinedX >= 0 and destinedY >= 0 and destinedY < n) {
                        insideProbability += (dp[x - 1][destinedX][destinedY]/8.0);
                    }
                }
                dp[x][i][j] = insideProbability;
            }
        }
    }
//    for (int x = 0; x < k; ++x) {
//        cout << x << endl;
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < n; ++j) {
//                cout << dp[x][i][j] << " ";
//            }
//            cout << endl;
//        }
//    }
    return dp[k - 1][row][column];
}

int main() {
    fastio();
//#ifndef _DEBUG
//    freopen("output.txt", "w", stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("debug.txt", "w", stderr);
//#endif
    int n, k, x, y;
    cin >> n >> k >> x >> y;
    cout << knightProbability(n, k, x, y);
}

