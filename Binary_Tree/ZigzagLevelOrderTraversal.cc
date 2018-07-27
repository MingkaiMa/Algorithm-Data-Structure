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
        
        vector<vector<int>> res;
        
        queue<TreeNode*> Queue;
        Queue.push(root);
        
        int count = 1;
        int direction = 1;
        
        while(!Queue.empty()){
            vector<TreeNode*> list;
            while(count > 0){
                TreeNode* node = Queue.front();
                Queue.pop();
                list.push_back(node);
                --count;
            }
            
            vector<int> rres;
            
            for(auto n: list){
                rres.push_back(n->val);
                if(n->left){
                    Queue.push(n->left);
                    count++;
                }
                if(n->right){
                    Queue.push(n->right);
                    count++;
                }
            }
            
            if(direction == 1){
                res.push_back(rres);
            }
            else{
                reverse(rres.begin(), rres.end());
                res.push_back(rres);
            }
            
            direction = 1 - direction;
        }
        
        return res;
    }
};
