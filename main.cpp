#include<bits/stdc++.h>

#define endl "\n"
using namespace std;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> input(n);
        for (int i = 0; i < n; ++i) {
            cin >> input[i];
        }
        int l = -1, r = -1;
        for (int i = 0; i < n - 1; ++i) {
            if (input[i] == input[i + 1]) {
                l = i;
                break;
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            if (input[i] == input[i + 1]) {
                r = i;
                break;
            }
        }
        if (n <= 2) {
            cout << 0 << endl;
        } else if (l == -1 or r == -1) {
            cout << 0 << endl;
        } else if (l == r) {
            cout << 0 << endl;
        } else if (r == (l + 1)) {
            cout << 1 << endl;
        } else {
            cout << r - l - 1 << endl;
        }
    }
}




