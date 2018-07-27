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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr)
            return {};
        
        stack<TreeNode*> levels[2];
        int current = 0;
        int next = 1;
        
        levels[current].push(root);
        
        vector<vector<int>> res;
        vector<int> rres;
        
        while(!levels[0].empty() || !levels[1].empty()){
            TreeNode* node = levels[current].top();
            levels[current].pop();
            
            rres.push_back(node->val);
            
            if(current == 0){
                if(node->left)
                    levels[next].push(node->left);
                if(node->right)
                    levels[next].push(node->right);
            }
            else{
                if(node->right)
                    levels[next].push(node->right);
                if(node->left)
                    levels[next].push(node->left);
            }
            
            
            if(levels[current].empty()){
                res.push_back(rres);
                rres.clear();
                current = 1 - current;
                next = 1 - next;
            }
            
            
        }
        
        return res;

    }
};
