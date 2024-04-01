/****************************************** inorder traversal approach without extra space **********************/
class Solution {
public:
    bool helper(TreeNode* root,TreeNode* &prev)
    {
        if (root == NULL) return true;

        if(helper(root->left, prev)==false)
        return false;

        if (prev != NULL && prev->val >= root->val) return false;
        prev = root;
        return helper(root->right, prev);
        
    }
    bool isValidBST(TreeNode* root) {
       TreeNode* prev = NULL;
        return helper(root, prev);
    }
};

//tc: O(n)
//space : O(h)


/**************************************** solution by comparing range **************************/
class Solution {
public:
    bool helper(TreeNode* root,long start, long end)
    {
        if (root == NULL) return true;

        if(root->val<= start || root->val >=end)
        return false;

        return helper(root->left ,start, root->val) && helper(root->right,root->val, end);
    }
    bool isValidBST(TreeNode* root) {
       return helper(root, LONG_MIN, LONG_MAX);
    }
};

//there is a test case where root is given INT_MAX so to handle it we have to take range from LONG_MIN to LONG_MAX. can be done using vvery big constant values in ramge
//tc: O(n)
//space : O(h)
