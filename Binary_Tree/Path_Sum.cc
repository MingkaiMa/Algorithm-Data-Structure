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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
        if(root == nullptr)
            return {};
        
        vector<vector<int>> res;
        
        stack<vector<TreeNode*>> Stack;
        Stack.push({root});
        
        while(!Stack.empty()){
            vector<TreeNode*> currList = Stack.top();
            Stack.pop();
            TreeNode* lastNode = currList[currList.size() - 1];
            
            if(lastNode->left == nullptr && lastNode->right == nullptr){
                
                if(calSum(currList) == sum){
                    vector<int> rrres;
                    for(auto& n: currList)
                    {
                        rrres.push_back(n->val);
                    }
                    res.push_back(rrres);
                }
            }
            else{
                if(lastNode->left)
                {
                    vector<TreeNode*> temp = currList;
                    temp.push_back(lastNode->left);
                    Stack.push(temp);
                }
                if(lastNode->right){
                    vector<TreeNode*> temp = currList;
                    temp.push_back(lastNode->right);
                    Stack.push(temp);
                }
            }
        }
        
        return res;
    }
    
    int calSum(vector<TreeNode*>& list){
        int s = 0;
        for(auto& n: list)
            s += n->val;
        
        return s;
    }
};
