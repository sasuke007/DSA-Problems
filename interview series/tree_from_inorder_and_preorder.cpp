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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    Solution(){

    }

    int find(vector<int> &arr,int elem,int start,int end){
        int index=-1;
        for(int i=start;i<=end;++i){
            if(arr[i]==elem){
                index=i;
                break;
            }
        }
        return index;
    }
    TreeNode * build(vector<int> &preorder,vector<int> &inorder,int start,int end,int &curr){
        int n=inorder.size();
        if(curr>=n){
            return nullptr;
        }
        if(start>end){
            return nullptr;
        }
        int val=preorder[curr];
        int pos = find(inorder,val,start,end);
        if(pos==-1){
            return nullptr;
        }
        TreeNode *current_node= new TreeNode(val);
        ++curr;
        current_node->left=build(preorder,inorder,start,pos-1,curr);
        current_node->right=build(preorder,inorder,pos+1,end,curr);
        return current_node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size()-1;
        int curr=0;
        return build(preorder,inorder,0,n,curr);
    }
};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> preorder(n),inorder(n);
    for(int i=0;i<n;++i){
        cin>>preorder[i];
    }
    for(int i=0;i<n;++i){
        cin>>inorder[i];
    }
    Solution s= *new Solution();
    cout<<s.buildTree(preorder,inorder);
}