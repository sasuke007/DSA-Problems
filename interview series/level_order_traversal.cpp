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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > level_order;
        if(root==nullptr){
            return level_order;
        }
        queue<TreeNode *> current_nodes;
        vector<int> level;
        current_nodes.push(root);
        level.push_back(root->val);
        while(!current_nodes.empty()){
            int nodes_in_current_level=current_nodes.size();
            level_order.push_back(level);
            level.clear();
            while(nodes_in_current_level--){
                TreeNode *node = current_nodes.front();
                current_nodes.pop();
                TreeNode * left_node = node->left;
                TreeNode * right_node=node->right;
                if(left_node!=nullptr){
                    level.push_back(left_node->val);
                    current_nodes.push(left_node);
                }
                if(right_node!=nullptr){
                    level.push_back(right_node->val);
                    current_nodes.push(right_node);
                }
            }
        }
        return level_order;
    }
};