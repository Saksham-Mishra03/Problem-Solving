class Solution {
public:
    void helper(TreeNode* root, int k,unordered_map<int,bool> &ump, bool &ans)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if(root==NULL)
        return;
        helper(root->left,k,ump,ans);
        if(root)
        {
            
            if(ump.find(root->val) != ump.end())
            {
                ans = true;
                return;
            }
            else
            {
                ump[k - root->val] = true;
            }
            
        }
        helper(root->right,k,ump,ans);
        
    }

    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,bool>ump;
        bool ans = false;
        helper(root,k,ump,ans);
        return ans;
    }
};
