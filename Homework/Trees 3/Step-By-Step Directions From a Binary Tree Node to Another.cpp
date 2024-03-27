/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode* LCA(TreeNode* root, int s, int d)
    {
        if(root==NULL)
        return NULL;

        if(root->val==s || root->val==d)
        return root;

        TreeNode *lans = LCA(root->left,s,d);
        TreeNode *rans = LCA(root->right,s,d);

        if(lans != NULL && rans!= NULL)
        return root;

        if(lans!=NULL)
        return lans;

        if(rans !=NULL)
        return rans;
    
        return NULL;
    }

    bool path(TreeNode* root, string &p1, int key)
    {
        if(root==NULL)
        return false;

        
        if(root->val == key )
        {
            return true;
        }
        p1 += 'L';
        if(path(root->left, p1,key))
        return true;

        p1.pop_back();
        
        
        if(root->val ==key)
        return true;
        p1 +='R';

        if(path(root->right,p1,key))
        return true;

        p1.pop_back();
        return false;

    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        root=LCA(root, startValue, destValue);
        string p1="";
        string p2 = "";
        path(root, p1, startValue);
        path(root, p2, destValue);

        for(int i = 0;i<p1.size();i++)
        {
            p1[i] = 'U';
        }
        return p1+p2;
    }
};
