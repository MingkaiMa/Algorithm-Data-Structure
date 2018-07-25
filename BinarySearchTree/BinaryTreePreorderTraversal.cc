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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr)
            return {};
        
        vector<int> res;
        
        stack<TreeNode*> Stack;
        Stack.push(root);
        
        while(!Stack.empty()) {
            TreeNode* currNode = Stack.top();
            Stack.pop();
            res.push_back(currNode->val);
            
            if(currNode->right != nullptr)
                Stack.push(currNode->right);
            
            if(currNode->left != nullptr)
                Stack.push(currNode->left);
        }
        
        return res;
    }
};
