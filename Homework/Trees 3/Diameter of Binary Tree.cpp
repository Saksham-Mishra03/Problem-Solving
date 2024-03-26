/************** approach by finding height sseparately *******************************************/

class Solution {
public:

    int height(TreeNode* root)
    {
        if(root==NULL)
        return 0;
        return 1+max(height(root->left),height(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int d1= height(root->left)+ height(root->right);
        int d2 = diameterOfBinaryTree(root->left);
        int d3 = diameterOfBinaryTree(root->right);
        return max(d1,max(d2,d3));
    }
};

/*************************************** ***********************************/
