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
        int n,k;
        cin>>n>>k;
        string stripe;
        cin>>stripe;
        int white_cells=0;
        for(int i=0;i<k;++i){
            if(stripe[i]=='W'){
                ++white_cells;
            }
        }
        int answer=white_cells;
        for(int i=k;i<n;++i){
            if(stripe[i]=='W'){
                ++white_cells;
            }
            if(stripe[i-k]=='W'){
                --white_cells;
            }
            answer=min(answer,white_cells);
        }
        cout<<answer<<endl;
    }
}

