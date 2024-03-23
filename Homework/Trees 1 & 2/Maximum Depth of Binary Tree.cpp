class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)
        return 0;

        int leftmax = maxDepth(root->left);
        int rightmax = maxDepth(root->right);

        return 1+ max(leftmax,rightmax);
        
    }
};
