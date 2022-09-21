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
    vector<int> a;
    int inf = 1e9+7;
    for(int i=0;i<a.size();++i){
        if(a[i]<0){
            a[i]=inf;
        }
    }
    for(int i=0;i<a.size();++i){
        if(a[i]>0 and a[i]<=n){
            int index = abs(a[i])-1;
            a[index]=-1*a[index];
        }
    }

}