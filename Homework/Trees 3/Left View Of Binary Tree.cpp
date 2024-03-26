/*********************** recursive solution *********************/
    

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
 /******************************* *****************************************/


/***************************level order solution **********************************/

vector<int> printLeftView(BinaryTreeNode<int>* root) {
    // Write your code here.
    vector<int>ans;
    if(root==NULL)
    return ans;

    queue<BinaryTreeNode<int>*>q;
    q.push(root);

    while(!q.empty())
    {
        int key = -1;
        int s = q.size();
        for(int i = 0;i<s;i++)
        {
            BinaryTreeNode<int>* front = q.front();
            q.pop();
            if(key==-1)
            key = front->data;

            if(front->left)
            q.push(front->left);

            if(front->right)
            q.push(front->right);
        }
        ans.push_back(key);
    }
    return ans;
}
/******************************* **************************************************/
