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

int solve(vector<vector<int> > &A, int B) {
    int n = A.size();
    int m = A[0].size();
    int i=0,j=m-1;
    int answer = INT_MAX;
    while(i<n && j>=0){
        if(B==A[i][j]){
            answer = min(answer,(i+1)*1009+(j+1));
            --j;
        }
        else if(B>A[i][j]){
            ++i;
        }
        else{
            --j;
        }
    }
    return answer==INT_MAX?-1:answer;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > arr(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
        }
    }
    int elem;
    cin >> elem;
    int b = -1;
    cout << solve(arr, elem) << endl;
}