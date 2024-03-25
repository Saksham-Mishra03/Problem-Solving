class Solution {
public:
 /* 
 //left view method with extra space of array to store left view
    
    vector<int>helper(TreeNode* root,vector<int>&ans, int lvl) {
    if(root==NULL) 
    return ans;

    if(ans.size()==lvl)
    ans.push_back(root->val);

    if(root->left)
    helper(root->left, ans, lvl+1);
    
    if(root->right)
    helper(root->right, ans, lvl+1);
    return ans;
    }

    int findBottomLeftValue(TreeNode* root) {
    //find left view of tthe tree
    vector<int>ans;
    helper(root,ans,0);
    return(ans[ans.size()-1]);
    }

    */


    //left view method without extra space of array to store left view
    int helper(TreeNode* root,int &ans, int lvl, int &cnt) {
        if(root==NULL) 
        return ans;

        if(cnt==lvl)
        {
            ans = root->val;
            cnt++;
        }

        if(root->left)
        helper(root->left, ans, lvl+1,cnt);
        
        if(root->right)
        helper(root->right, ans, lvl+1,cnt);
        
        return ans;
    }

    int findBottomLeftValue(TreeNode* root) {
    //find left view of tthe tree
    
        int ans;
        int cnt=0;
        helper(root,ans,0,cnt);
        return ans;

    }
    
};
