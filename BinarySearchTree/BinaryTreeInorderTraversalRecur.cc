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
    
    vector<int> inorderTraversal(TreeNode* root) {
        core(root);
        return res;
    }
    
    void core(TreeNode* root)
    {
        if(root == nullptr)
            return;
        
        core(root->left);
        res.push_back(root->val);
        core(root->right);
    }
};
