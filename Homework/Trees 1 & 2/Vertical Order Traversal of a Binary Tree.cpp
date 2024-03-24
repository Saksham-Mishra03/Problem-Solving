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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<vector<int>>res;
        if(root==NULL)
        return res;

        map<int,map<int,vector<int>>>nodes;                  //table bnaega. hd ko map krege(level se and har lebel pr kitn element h us hd pe store krega)
        queue<pair<TreeNode*,pair<int,int>>>q;               //1st int hd, 2nd lvl

        q.push(make_pair(root,make_pair(0,0)));

        while(!q.empty())
        {
            pair<TreeNode*,pair<int,int>>front = q.front();
            q.pop();
            TreeNode *fn = front.first;
            int hd = front.second.first;
            int lvl = front.second.second;

            nodes[hd][lvl].push_back(fn->val);

            if(fn->left)
            q.push(make_pair(fn->left,make_pair(hd-1,lvl+1)));

            if(fn->right)
            q.push(make_pair(fn->right,make_pair(hd+1,lvl+1)));
        }

        for(auto i : nodes){
            vector<int> ans;
            for(auto j : i.second){
                vector<int> &v = j.second;
                sort(v.begin(),v.end());
                ans.insert(ans.end(),v.begin(),v.end());
            }
            res.push_back(ans);
        }
        return res;
    }
};
