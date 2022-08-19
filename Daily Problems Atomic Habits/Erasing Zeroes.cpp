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
        string input;
        cin>>input;
        int answer =0;
        int ones_index=-1;
        int n=input.size();
        for(int i=0;i<n;++i){
            if(input[i]=='1'){
                if(ones_index!=-1){
                    answer+=(i-ones_index-1);
                }
                ones_index=i;
            }
        }
        cout<<answer<<endl;
    }
}