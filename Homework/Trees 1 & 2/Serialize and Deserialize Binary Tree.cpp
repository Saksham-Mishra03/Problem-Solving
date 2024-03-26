/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        if(root==NULL)
        return ans;

        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode *front = q.front();
            q.pop();

            if(front==NULL)
            {
                ans += '$';
                ans += ',';
            }
            else
            {
                ans += to_string(front->val);
                ans += ',';
            }
            if(front!=NULL)
            {
                q.push(front->left);
                q.push(front->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "")
        return NULL;

        string str;
        stringstream s(data);
        getline(s,str,',');

        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* front = q.front();
            q.pop();

            getline(s,str,',');
            if(str == "$")
            front->left = NULL;

            else
            {
                TreeNode* l = new TreeNode(stoi(str));
                front->left = l;
                q.push(l);
            }

            getline(s,str,',');
            if(str== "$")
            front->right = NULL;
            else
            {
                TreeNode* r = new TreeNode(stoi(str));
                front->right = r;
                q.push(r);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
