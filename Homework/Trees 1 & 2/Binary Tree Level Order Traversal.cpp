class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

//edge case
        if(root==NULL)
        {
        vector<vector<int>>res;
        return res;
        }


        vector<vector<int>>res;
        vector<int>ans;
        queue<TreeNode*>q;

        q.push(root);
        q.push(NULL);//act as terminator for root node
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            if(temp!=NULL)
            {
                if(temp->left != NULL) 
                q.push(temp->left); 
                if(temp->right != NULL) 
                q.push(temp->right); 
                
                ans.push_back(temp->val);
            }
            else //temp==NULL that means ab is level pr kuch ni bacha sare elements le lie islie vector for final vector me push kro ar queue me ek ar null dal do termination k lie
            {
                if(!q.empty())
                {
                q.push(NULL);
                res.push_back(ans);
                ans.resize(0);
                }
            }
        }
        res.push_back(ans);
        return res;
    }
};
