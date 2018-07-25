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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr)
            return {};
        
        stack<TreeNode*> Stack;
        
        TreeNode* curr = root;
        
        while(curr) {
            Stack.push(curr);
            curr = curr->left;
        }
        
        vector<int> res;
        
        while(!Stack.empty()) {
            TreeNode* currNode = Stack.top();
            Stack.pop();
            
            res.push_back(currNode->val);
            
            if(currNode->right != nullptr) {
                TreeNode* temp = currNode->right;
                while(temp) {
                    Stack.push(temp);
                    temp = temp->left;
                }
            }
        }
        
        return res;
    }
};
