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

class LRUCache {
private:
    list<pair<int,int> > cache;
    unordered_map<int,list<pair<int,int> >::reverse_iterator> present;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
    }

    int get(int key) {
        if(present.find(key)==present.end()){
            return -1;
        }

    }

    void put(int key, int value) {
        if(cache.size()<capacity){
            cache.emplace_back(key,value);
            present[key]=cache.rbegin();
        }
        else{
            pair<int,int> val=cache.front();
            cache.erase(cache.begin());
            present.erase(val.first);
            cache.emplace_back(key,value);
            present[key]=cache.rbegin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

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
        vector<int> prefix_sum(n+1,0);
        for(int i=0;i<n;++i){
            if(input[i]<(i+1)){
                prefix_sum[i+1]=prefix_sum[i]+1;
            }
            else{
                prefix_sum[i+1]=prefix_sum[i];
            }
        }
        long long answer =0;
        for(int i=0;i<n;++i){
            if(input[i]<(i+1)){
                int val=input[i];
                answer+=(val-1>=0?prefix_sum[val-1]:0);
            }
        }
        cout<<answer<<endl;
    }
}

