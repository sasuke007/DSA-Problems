#include<bits/stdc++.h>

#define endl "\n"
using namespace std;

int findFirstMissingPositiveInteger(vector<int> input) {
    int n = input.size();
    for (int i = 0; i < n; ++i) {
        if (input[i] <= 0) {
            input[i] = 1e9;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (input[i] > n) {
            continue;
        }
        int val = abs(input[i]);
        if (input[val - 1] > 0) {
            input[val - 1] = -1 * input[val - 1];
        }
    }
    int missingPositiveInteger = n;
    for (int i = 0; i < n; ++i) {
        if (input[i] > 0) {
            missingPositiveInteger = i;
            break;
        }
    }
    return missingPositiveInteger + 1;
}


int no_of_ways(int n,int k){
    vector<int> dp(n+1,0);
    dp[0]=1;
    for(int i=1;i<n+1;++i){
        for(int j=1;j<=k;++j){
            dp[i]+=(i-j)>=0?dp[i-j]:0;
        }
    }
    return dp[n];
}



int main() {
    vector<int> input = {2, 1, 1, 3, 6};
    cout << findFirstMissingPositiveInteger(input);
}




