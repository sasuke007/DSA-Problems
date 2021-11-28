#include <math.h>

#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
#define endl "\n"
typedef long long ll;
int count_abc(string &input) {
  int n = input.size();
  int count = 0;
  for (int i = 0; i < n - 2; ++i) {
    if (input[i] == 'a' and input[i + 1] == 'b' and input[i + 2] == 'c') {
      ++count;
    }
  }
  return count;
}
int formed(string &input, int pos, char c) {
  int n = input.size();
  if (c == 'a' and pos + 2 < n and input[pos + 1] == 'b' and
      input[pos + 2] == 'c') {
    return 1;
  } else if (c == 'b' and pos + 1 < n and pos - 1 >= 0 and
             input[pos - 1] == 'a' and input[pos + 1] == 'c') {
    return 1;
  } else if (c == 'c' and pos - 2 >= 0 and input[pos - 1] == 'b' and
             input[pos - 2] == 'a') {
    return 1;
  }
  return 0;
}
int destroyed(string &input, int pos, char c) {
  int n = input.size();
  if (input[pos] == 'a' and pos + 2 < n and input[pos + 1] == 'b' and
      input[pos + 2] == 'c') {
    return 1;
  } else if (input[pos] == 'b' and pos + 1 < n and pos - 1 >= 0 and
             input[pos - 1] == 'a' and input[pos + 1] == 'c') {
    return 1;
  } else if (input[pos] == 'c' and pos - 2 >= 0 and input[pos - 1] == 'b' and
             input[pos - 2] == 'a') {
    return 1;
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
#endif

  int n, q;
  cin >> n >> q;
  string input;
  cin >> input;
  int count = count_abc(input);
  while (q--) {
    int pos;
    char c;
    cin >> pos >> c;
    --pos;
    // is_destroyed
    if (input[pos] != c) {
      count += formed(input, pos, c);
      count -= destroyed(input, pos, c);
      input[pos] = c;
    }
    // formed_new;
    cout << count << endl;
  }
}