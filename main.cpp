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
#include<bits/stdc++.h>

#define endl "\n"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n,q;
        cin>>n>>q;
        vector<int> power(n);
        for(int i=0;i<n;++i){
            cin>>power[i];
        }
        vector<int> winners(n-1);
        int winner_untill_now=0;
        for(int i=1;i<n;++i){
           if(power[winner_untill_now]<power[i]){
               winner_untill_now=i;
               winners[i]=i;
           }
           else{
               winners[i]=winner_untill_now;
           }
        }
        while(q--){
            int player,round;
            cin>>player>>round;
            if(round)
        }
    }
}