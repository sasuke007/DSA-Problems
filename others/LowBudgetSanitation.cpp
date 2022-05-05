#include <iostream>
#include <vector>
using namespace std;
#define endl "\n"
typedef long long ll;
int main() {
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
#endif
  cin.tie(0);
  ios::sync_with_stdio(false);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > germs_position;
    for (int i = 0; i < n; ++i) {
      // first query
      cout << 1 << " " << 1 << " " << -1 << " " << 0 << endl;
      cout.flush();
      ll id;
      ll d1;
      cin >> id >> d1;
      // second query
      cout << 1 << " " << 1 << " " << 1 << " " << 0 << endl;
      cout.flush();
      ll d2;
      cin >> id >> d2;
      // print answer
      ll destroyed;
      cout << 2 << " " << (d1 + d2) / 2 << " " << (d2 - d1) / 2 << endl;
      cout.flush();
      cin >> destroyed;
      if (destroyed != 0) {
        return 0;
      }
      cout.flush();
    }
  }
}