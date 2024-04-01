void helper(Node* root, int input, int &ans)
{
     if (root == NULL) 
     return;
    if(root->data==input)
    {
        ans = root->data;
        return;
    }
    
    else if(root->data<input)
    helper(root->right,input,ans);
    
    else
    {
        ans  = root->data;
        helper(root->left,input,ans);
    }
}

int findCeil(Node* root, int input) {
    
    int ans = -1;
    helper(root, input, ans);
    return ans;
    
    
    // Your code here
}
