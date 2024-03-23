//if any 2 order traversals same then same treee bali approach
class Solution {
public:
void inorder(TreeNode* root, vector<int>&v)
{
    if(root!=NULL)
        {
            inorder(root->left,v);
            v.push_back(root->val);
            inorder(root->right,v);
        }
     else {v.push_back(100000);}

}
void preorder(TreeNode* root, vector<int>&v)
{
    if(root!=NULL)
        {
            v.push_back(root->val);
            preorder(root->left,v);
            
            preorder(root->right,v);
        }
        else{ v.push_back(100000);}

}

    bool isSameTree(TreeNode* p, TreeNode* q) {

        vector<int> inp,inq,prep,preq;
        inorder(p,inp);
        inorder(q,inq);
         preorder(p,prep);
        preorder(q,preq);

        if(inp==inq && prep == preq)
        return true;
        else
        return false;
        
    }
};

/***********************************************************************************************************************************/

//checking each node approach
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if(!p && !q)
        return true;

        if(p && !q || q && !p)
        return false;

        if(p->val != q->val)
        return false;

        return isSameTree(p->left , q->left ) && isSameTree(p->right, q->right);
    }
};
