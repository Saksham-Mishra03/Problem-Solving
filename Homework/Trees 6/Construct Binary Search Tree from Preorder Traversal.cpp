class Solution {
public:
    TreeNode* helper(vector<int>& preorder, int start, int end)
    {
        /*
        if(preorder.size()==1)
        return new TreeNode(preorder[0]);
        */

        if(end<start)
        return NULL;

        TreeNode* root = new TreeNode(preorder[start]);
        int i = start+1;
        for(;i<=end;i++)
        {
            if(preorder[i]>preorder[start])
            {
                break;
            }
        }
        root->left = helper(preorder,start+1,i-1);
        root->right = helper(preorder,i, end);

        return root;

    } 
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int start = 0;
        int end = preorder.size()-1;
        //int n = preoreder.size();
        return helper(preorder,start,end);
        
    }
};
