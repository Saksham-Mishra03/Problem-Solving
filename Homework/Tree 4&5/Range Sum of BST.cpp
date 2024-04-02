class Solution {
public:
    int sum = 0;
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL)
        return 0;

        if(root->val<=high && root->val>=low)
        {
            return root->val + rangeSumBST(root->left,low,high) + rangeSumBST(root->right,low,high);
        }
        
        if(root->val > high)
        {
            return rangeSumBST(root->left, low, high);
        }


        if(root->val < low)
        {
            return rangeSumBST(root->right, low, high);
        }
        return sum;
    }
};
