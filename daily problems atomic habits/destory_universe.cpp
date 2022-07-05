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
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        vector<int> input(n);
        for(int i=0;i<n;++i){
            cin>>input[i];
        }
        vector<int> zero_positions;
        zero_positions.push_back(0);
        for(int i=0;i<n;++i){
            if(input[i]==0){
                zero_positions.push_back(i+1);
            }
        }
        zero_positions.push_back(n+1);
        int count = 0;
        for(int i=0;i<zero_positions.size()-1;++i){
            if(zero_positions[i+1]-zero_positions[i]>1)
                ++count;
        }
        cout<<min(count,2)<<endl;
    }

