class Solution {
public:

    void helper(TreeNode * root, vector<vector<int>>&ans, vector<int>temp, int sum, int &targetSum )
    {
        if(root==NULL) return;

        sum += root->val;
        temp.push_back(root->val);
        if(root->left==NULL && root->right==NULL)
        {
            if(sum==targetSum)
            {
                ans.push_back(temp);
            }
            return;
        }
        helper(root->left, ans, temp, sum, targetSum );
        helper(root->right, ans, temp, sum, targetSum );

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;

        if(root==NULL)
        return ans;

        vector<int>temp;
        int sum = 0;

        helper(root, ans, temp, 0, targetSum );
        return ans;

    }
};
