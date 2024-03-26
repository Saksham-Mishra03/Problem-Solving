/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool helper(TreeNode *A,vector<int> &path, int B)
{
    if(A==NULL)
    return false;
    
    if(A->val==B || helper(A->left,path,B) || helper(A->right,path,B))
    {
        path.push_back(A->val);
        return true;
    }
    return false;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    
    vector<int>path;
    helper(A,path,  B);
    reverse(path.begin(),path.end());
    return path;
    
}
