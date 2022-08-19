/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int diameter=0;
public:
    int find_diameter(TreeNode * root){
        if(root==nullptr){
            return 0;
        }
        int left_subtree=find_diameter(root->left);
        int right_subtree=find_diameter(root->right);
        diameter=max(diameter,left_subtree+right_subtree);
        return max(left_subtree,right_subtree)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        find_diameter(root);
        return diameter;
    }
};