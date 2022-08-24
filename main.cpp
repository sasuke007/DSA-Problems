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
        int n;
        cin>>n;
        vector<int> input(n);
        for(int i=0;i<n;++i){
            cin>>input[i];
        }
        sort(input.begin(),input.end());
        if(input[1]!=0 or input[n-2]!=0){
            cout<<"NO"<<endl;
        }
        else if(input[n-1]==0 or input[0]==0){
            cout<<"YES"<<endl;
        }
        else if(input[n-1]+input[0]==0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<
        }
    }
}