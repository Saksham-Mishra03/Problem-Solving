class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root->val==p->val || root->val==q->val)
        return root;

        TreeNode* lans = lowestCommonAncestor(root->left, p,q);
        TreeNode* rans = lowestCommonAncestor(root->right, p,q);

        if(lans!=NULL and rans != NULL)
        return root;

        if(lans!=NULL)
        return lans;

        if(rans!=NULL)
        return rans;

        return NULL;
    }
};
