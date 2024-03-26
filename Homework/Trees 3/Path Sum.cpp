class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {

        if(root==NULL)
        return false;
        if( root->left==NULL && root->right==NULL)
        {
            if(root->val==targetSum)
            return true;
            else
            return false;
        }
        return hasPathSum(root->left,targetSum-root->val) || hasPathSum(root->right,targetSum-root->val);

    }
};
