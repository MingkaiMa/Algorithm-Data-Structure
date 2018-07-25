/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> res;
    
    vector<int> preorderTraversal(TreeNode* root) {
        core(root);
        return res;
    }
    
    void core(TreeNode* root){
        if(root == nullptr)
            return;
        
        res.push_back(root->val);
        core(root->left);
        core(root->right);
    }
};
