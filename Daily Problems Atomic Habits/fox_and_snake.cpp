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
    int n,m;
    cin>>n>>m;
    vector<vector<char> > input(n,vector<char>(m,'.'));
    for(int i=0;i<n;i+=2){
        for(int j=0;j<m;++j){
            input[i][j]='#';
        }
    }
    bool first=false;
    for(int i=1;i<n;i+=2){
        if(first){
            input[i][0]='#';
        }else{
            input[i][m-1]='#';
        }
        first=1-first;
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cout<<input[i][j];
        }
        cout<<endl;
    }
}