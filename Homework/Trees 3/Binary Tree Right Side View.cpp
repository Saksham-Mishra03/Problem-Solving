/************************************* level order solution*****************************/

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int>ans;
        if(root==NULL)
        return ans;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            int key=0;
            int s = q.size();
            for(int i =0;i<s;i++)
            {
                TreeNode *front = q.front();
                key = front->val;
                q.pop();

                if(front->left)
                q.push(front->left);
                if(front->right)
                q.push(front->right);
                
            }
            ans.push_back(key);
        }
        return ans;
    }
};
/**************************************** ***********************************************/


/********************************recursive solution********************************/

class Solution {
public:

    vector<int> helper(TreeNode* root, vector<int>&ans, int lvl)
    {
        if(root==NULL)
        return ans;

        if(ans.size()==lvl)
        ans.push_back(root->val);

        if(root->right)
        helper(root->right,ans, lvl+1);

        if(root->left)
        helper(root->left,ans,lvl+1);

        return ans;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        //int lvl = 0;
        return helper(root, ans, 0);
        
    }
};
/********************************************* ******************************************/
