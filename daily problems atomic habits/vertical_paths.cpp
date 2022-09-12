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

int dfs(vector<vector<int> > &tree,int root,int &cuts,vector<pair<int,int> > &paths){
    int len=tree[root].size();
    cuts+=max(0,len-1);
    int nodes=0;
    for(int i=0;i<tree[root].size();++i){
        int child=tree[root][i];
        int count=dfs(tree,child,cuts,paths);
        if(i==0){
            nodes=count;
        }
        if(i!=0) {
            paths.emplace_back(child, count);
        }
    }
    return nodes+1;
}
void traverse_path(vector<vector<int> >&tree,int node){
    cout<<node<<" ";
    if(tree[node].size()>0){
        traverse_path(tree,tree[node][0]);
    }
}
int main() {
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        vector<vector<int> > tree(n+1);
        int root=-1;
        for(int i=1;i<=n;++i){
            int val;
            cin>>val;
            if(val==i){
                root=i;
            }
            else{
                tree[val].push_back(i);
            }
        }
        int cuts=1;
        vector<pair<int,int> > paths;
        int count = dfs(tree,root,cuts,paths);
        paths.emplace_back(root,count);
        cout<<cuts<<endl;
        for(int i=0;i<paths.size();++i){
            cout<<paths[i].second<<endl;
            traverse_path(tree,paths[i].first);
            cout<<endl;
        }
    }
}

