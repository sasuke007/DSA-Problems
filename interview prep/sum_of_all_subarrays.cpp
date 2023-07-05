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