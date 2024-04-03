class Solution {
public:
    void inorder(TreeNode* root, int &cnt, int &ans, int k){
        if(root == NULL)   
        return;

        inorder(root->left, cnt, ans, k);
         cnt++;
        if(cnt == k){
            ans = root->val;
            return;
        }
       
        inorder(root->right, cnt, ans, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        
        int cnt = 0;        
        int ans;
        inorder(root, cnt, ans, k);
        return ans;
    }
};
