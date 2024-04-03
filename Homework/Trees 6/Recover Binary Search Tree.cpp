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

    void helper(TreeNode* root,TreeNode* &prev,TreeNode* &E1,TreeNode* &E2, bool &found1)
    {
        if(root==NULL)
        return;
        helper(root->left,prev,E1,E2,found1);
        if(root->val <prev->val && !found1)
        {
            E1 = prev;
            E2 = root;
            found1 = true;
        }
        else if(root->val <prev->val)
        {
            E2 = root;
        }
        prev = root;
        helper(root->right,prev,E1,E2,found1);
    }
    void recoverTree(TreeNode* root) {
        if(root==NULL)
        return;
        TreeNode *prev = new TreeNode(INT_MIN);
        TreeNode *E1 =NULL;
        TreeNode *E2 = NULL;
        bool found1 = false;
        helper(root,prev,E1,E2,found1);
        swap(E1->val,E2->val);
    }
};

//TC : O(n)
//Space : O(h)
