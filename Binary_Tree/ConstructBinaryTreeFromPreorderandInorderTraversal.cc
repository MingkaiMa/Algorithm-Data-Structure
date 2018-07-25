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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0 || inorder.size() == 0 || preorder.size() != inorder.size())
            return nullptr;
        
        if(preorder.size() == 1 && inorder.size() == 1) {
            TreeNode* newNode = new TreeNode(preorder[0]);
            return newNode;
        }
        
        
        TreeNode* root = new TreeNode(preorder[0]);
        
        auto findRoot = find(inorder.begin(), inorder.end(), root->val);
        
        vector<int> inLeftNodes(inorder.begin(), findRoot);
        vector<int> inRightNodes(findRoot + 1, inorder.end());
        
        vector<int> preLeftNodes(preorder.begin() + 1, preorder.begin() + 1 + inLeftNodes.size());
        vector<int> preRightNodes(preorder.begin() + 1 + inLeftNodes.size(), preorder.end());
        
        
        root->left = buildTree(preLeftNodes, inLeftNodes);
        root->right = buildTree(preRightNodes, inRightNodes);
        
        return root;
    }
};
