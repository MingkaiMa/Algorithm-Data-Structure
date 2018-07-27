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
        
        stack<vector<TreeNode*>> Stack;
        
        Stack.push({root});
        
        vector<vector<int>> res;
        
        while(!Stack.empty()){
            vector<TreeNode*> currList = Stack.top();
            Stack.pop();
            vector<int> rres;
            for(auto n: currList){
                rres.push_back(n->val);
            }
            res.push_back(rres);
            vector<TreeNode*> tempListNodes;
            for(auto node: currList){
                if(node->left)
                    tempListNodes.push_back(node->left);
                if(node->right)
                    tempListNodes.push_back(node->right);
                    
            }
            Stack.push(tempListNodes);
            
        }
        
        return res;
    }
};
