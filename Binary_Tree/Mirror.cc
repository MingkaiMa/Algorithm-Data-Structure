Binary Tree Mirror

void Mirror(TreeNode* root){
	if(root == nullptr)
		Return;
	
	TreeNode* temp = root->left;
	root->left = root->right;
	root->right = temp;

	Mirror(root->left);
	Mirror(root->right);
}
