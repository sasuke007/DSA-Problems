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

void solve() {}
int find_primes_in_range(vector<int> &prime_prefix, int num) {
  int period = 60;
  int primes = 0;
  int n = prime_prefix.size();
  primes += (num / period) * prime_prefix[n - 1];
  primes += prime_prefix[num % period];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int a, b;
  cin >> a >> b;
  vector<int> fib_prime;
  ll a = 1;
  ll b = 1;
  fib_prime.push_back(1);
  fib_prime.push_back(1);
  for (int i = 3; i < 60; ++i) {
    ll temp = a + b;
    fib_prime.push_back(temp % 10);
    a = b;
    b = temp;
  }
  vector<int> prime_prefix(61, 0);
  set<int> single_digit_primes = {2, 3, 5, 7};
  for (int i = 1; i < prime_prefix.size(); ++i) {
    prime_prefix[i] =
        prime_prefix[i - 1] +
        (single_digit_primes.find(fib_prime[i - 1]) != single_digit_primes.end()
             ? 1
             : 0);
  }
  cout << find_primes_in_range(prime_prefix, b) -
              find_primes_in_range(prime_prefix, a - 1);
}