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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr)
            return {};
        
        queue<TreeNode*> Queue;
        Queue.push(root);
        
        int nextLevel = 0;
        int toBePrinted = 1;
        
        vector<vector<int>> res;
        vector<int> rres;
        
        while(!Queue.empty()){
            
            
            TreeNode* currNode = Queue.front();
            rres.push_back(currNode->val);
            
            if(currNode->left)
            {
                Queue.push(currNode->left);
                nextLevel++;
            }
            
            if(currNode->right){
                Queue.push(currNode->right);
                nextLevel++;
            }
            
            Queue.pop();
            --toBePrinted;
            
            if(toBePrinted == 0){
                res.push_back(rres);
                toBePrinted = nextLevel;
                nextLevel = 0;
                rres.clear();
            }
            
        }
        
        return res;
    }
};
