vector<int> helper(BinaryTreeNode<int> *root,vector<int>&ans, int lvl) {
    if(root==NULL) 
    return ans;

    if(ans.size()==lvl)
    ans.push_back(root->data);

    if(root->left)
    helper(root->left, ans, lvl+1);
    
    if(root->right)
    helper(root->right, ans, lvl+1);

    return ans;
}

vector<int> printLeftView(BinaryTreeNode<int>* root) {
    // Write your code here.

    vector<int>ans;
    return helper(root,ans,0);
}
