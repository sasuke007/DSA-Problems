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
    vector<vector<int> > input(5,vector<int>(5));
    pair<int,int> one_index;
    for(int i=0;i<5;++i){
        for(int j=0;j<5;++j){
            int val;
            cin>>val;
            if(val==1){
                one_index.first=i;
                one_index.second=j;
            }
        }
    }
    cout<<abs(one_index.first-2)+abs(one_index.second-2)<<endl;
}