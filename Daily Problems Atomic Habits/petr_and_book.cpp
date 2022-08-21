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
#include<set>

#define endl "\n"
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int day = -1;
    int current = 0;
    vector<int> pages(7);
    for(int i=0;i<7;++i){
        cin>>pages[i];
    }
    while (current<n) {
        for (int i = 0; i < 7; ++i) {
            int val=pages[i];
            current += val;
            if (current >= n) {
                day = i + 1;
                break;
            }
        }
    }
    cout << day << endl;
}