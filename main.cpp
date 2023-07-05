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

vector<int> minDifference(vector<int> &nums, vector<vector<int>> &queries) {
    vector<vector<int> > dp(nums.size() + 1, vector<int>(101, 0));
    for (int i = 1; i < nums.size() + 1; ++i) {
        for (int j = 0; j < 101; ++j) {
            if (j == nums[i]) {
                dp[i][j] = dp[i - 1][j] + 1;
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    for (int i = 0; i < dp.size(); ++i) {
        for (int j = 0; j < dp[0].size(); ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    vector<int> answer;
    for (vector<int> query: queries) {
        int minDifference = INT_MAX;
        int l = query[0];
        int r = query[1];
        int s = r - l + 1;
        int previousNumber = -1;
        for (int i = 0; i < 100; ++i) {
            int freq = dp[r + 1][i] - dp[l][i];
            if (freq == 0) {
                continue;
            }
            if (freq == s) {
                minDifference = -1;
                break;
            } else {
                if (previousNumber == -1) {
                    previousNumber = i;
                } else {
                    minDifference = min(minDifference, i - previousNumber);
                    previousNumber = i;
                }
            }
        }
        answer.push_back(minDifference);
    }
    return answer;
}
int solve(vector<vector<int> > arr){
    int n=arr.size();
    int m=arr[0].size();
    int answer =0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            int upper = (i+1)*(j+1);
            int lower = (n-i)*(m-j);
            answer += upper * lower * arr[i][j];
        }
    }
    return answer;
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int> > arr(n,vector<int>(m));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>arr[i][j];
        }
    }
    cout<<solve(arr);
}

