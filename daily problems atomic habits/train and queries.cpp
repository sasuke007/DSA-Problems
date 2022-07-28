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

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,k;
        cin>>n>>k;
        unordered_map<int,pair<int,int> > position;
        for(int i=0;i<n;++i){
            int val;
            cin>>val;
            if(position.count(val)==0){
                position[val].first=i;
                position[val].second=i;
            }
            else{
                position[val].second=i;
            }
        }
        while(k--){
            int a,b;
            cin>>a>>b;
            if(position.count(a)==0 or position.count(b)==0 or position[a].first>position[b].second){
                cout<<"NO"<<endl;
            }
            else{
                cout<<"YES"<<endl;
            }
        }
    }
}

