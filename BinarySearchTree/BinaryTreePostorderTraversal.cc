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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr)
            return {};
        
        stack<TreeNode*> Stack;
        vector<TreeNode*> printedNode;
        
        vector<int> res;
        
        TreeNode* curr1 = root;
        
        while(curr1){
            Stack.push(curr1);
            curr1 = curr1->left;
        }
        
        while(!Stack.empty()){
            TreeNode* curr = Stack.top();
            
            if(curr->right == nullptr)
            {
                res.push_back(curr->val);
                printedNode.push_back(curr);
                Stack.pop();
            }
            else {
                TreeNode* temp = curr->right;
                auto findOne = find(printedNode.begin(), printedNode.end(), temp);
                
                if(findOne == printedNode.end()) {
                    while(temp){
                        Stack.push(temp);
                        temp = temp->left;
                    }
                }
                else {
                    res.push_back(curr->val);
                    printedNode.push_back(curr);
                    Stack.pop();
                }

                
            }
            
        }
        return res;
    }
};
