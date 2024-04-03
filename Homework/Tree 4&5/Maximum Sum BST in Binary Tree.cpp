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
class info{
    public:
    bool isBST;
    int maxi;
    int mini;
    int sum;

    info()
    {
        isBST = true;
        maxi = INT_MIN;
        mini = INT_MAX;
        sum = 0;
    }
};
class Solution {
public:

    info helper(TreeNode* root, int&ans)
    {
        if(root==NULL)
        return info();

        info lt = helper(root->left,ans);
        info rt = helper(root->right,ans);

        info newnode;
        //check if the newnode is included in bst or not
        if(lt.isBST && rt.isBST && (root->val>lt.maxi) && root->val<rt.mini)
            newnode.isBST = true;
        else
            newnode.isBST = false;

        // find max element of newnode bala bst
        newnode.maxi = max(root->val,rt.maxi);
        // find  min element of newnode bala bst
        newnode.mini = min(root->val,lt.mini);

        //update the sum
        if(newnode.isBST)
        {
            newnode.sum  = lt.sum + rt.sum + root->val;
        }
        else
        {
            newnode.sum  = max(lt.sum,rt.sum);
        }
        ans = max(ans,newnode.sum);
        return newnode;

    }
    int maxSumBST(TreeNode* root) {

        int ans = 0;
        helper(root,ans);
        return ans;
        
    }
};


//TC: O(N)
//Sppace O(2H)
