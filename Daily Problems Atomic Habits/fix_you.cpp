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
    int tc;
    cin>>tc;
    while(tc--){
        int n,m;
        cin>>n>>m;
        vector<vector<char> > input(n,vector<char>(m));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                cin>>input[i][j];
            }
        }
        int answer=0;
        for(int i=0;i<m-1;++i){
            if(input[n-1][i]=='D'){
                ++answer;
            }
        }
        for(int i=0;i<n-1;++i){
            if(input[i][m-1]=='R'){
                ++answer;
            }
        }
        cout<<answer<<endl;
    }
}