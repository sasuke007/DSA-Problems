#include<bits/stdc++.h>

#define endl "\n"
using namespace std;

bool check(char ch, char start, char end) {
    if (start >= end) {
        return ch >= end and ch <= start;
    } else {
        return ch >= start and ch <= end;
    }
}

void print(vector<pair<int, int> > &arr) {
    for (pair<int, int> &pi: arr) {
        cout << pi.first << " " << pi.second << endl;
    }
    cout << endl;
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> eat(n), money(n);
        for (int i = 0; i < n; ++i) {
            cin >> eat[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> money[i];
        }
        vector<pair<int, int> > insufficient, sufficient;
        for (int i = 0; i < n; ++i) {
            if (eat[i] > money[i]) {
                insufficient.emplace_back(eat[i], money[i]);
            } else {
                sufficient.emplace_back(eat[i], money[i]);
            }
        }
        sort(insufficient.begin(), insufficient.end(), [](pair<int, int> &a, pair<int, int> &b) {
            return a.first - a.second > b.first - b.second;
        });
        sort(sufficient.begin(), sufficient.end(), [](pair<int, int> &a, pair<int, int> &b) {
            return a.first - a.second < b.first - b.second;
        });
        //print(insufficient);
        //print(sufficient);
        int match = 0;
        int i = 0, j = 0;
        while (i < insufficient.size() and j < sufficient.size()) {
            if ((insufficient[i].first - insufficient[i].second) <= (sufficient[j].second - sufficient[j].first)) {
                ++match;
                ++i;
                ++j;
            } else {
                ++i;
            }
        }
        cout << match + (sufficient.size() - j) / 2<<endl;
    }
}


