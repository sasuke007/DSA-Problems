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
        string layout;
        cin>>layout;
        int answer =0;
        for(int i=0;i<n;++i){
            if(layout[i]=='0'){
                answer+=1;
            }
            else{
                answer+=2;
            }
        }
        cout<<answer<<endl;
    }
}