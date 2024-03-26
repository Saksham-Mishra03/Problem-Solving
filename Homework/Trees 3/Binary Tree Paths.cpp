class Solution {
public:

    void helper(TreeNode* root, vector<string>& ans, string str)
    {
        if(!root)
        {
            if(str.empty()) //root null ho jae and string bhi khali aye iska mtlb tree khatam ho gya h ar usko ans me bhej de
            return;

            else
            ans.push_back(str);
            return;
        }

        str = str+ to_string(root->val);
        if(root->left || root->right)
        {
            str+= "->";
        }
        else
        {
            ans.push_back(str);
        }

        if(root->left)
        helper(root->left,ans,str);

        if(root->right)
        helper(root->right,ans,str);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string str;
        helper(root,ans,str);
        return ans;
    }
};
