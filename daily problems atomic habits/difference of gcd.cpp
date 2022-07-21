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

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> answer;
        bool found = false;
        for (int i = 1; i <= n; ++i) {
            int number = (((l - 1) / i) + 1) * i;
            if (number > r) {
                found=true;
                break;
            }
            answer.push_back(number);
        }
        if(found==true){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
            for(int i=0;i<n;++i){
                cout<<answer[i]<<" ";
            }
            cout<<endl;
        }
    }
}

