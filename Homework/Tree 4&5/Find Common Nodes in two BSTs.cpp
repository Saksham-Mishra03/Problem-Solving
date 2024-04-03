class Solution
{
    public:
    //Function to find the nodes that are common in both BST. 
    void inorder(Node *root, unordered_map<int,int>&ump, vector<int>&ans)
    {
       if(root==NULL)
       return;
       
       inorder(root->left,ump,ans);
       if(ump.find(root->data)!= ump.end())
       ans.push_back(root->data);
       else
       ump[root->data]++;
       
       inorder(root->right,ump,ans);
    }
    vector <int> findCommon(Node *root1, Node *root2)
    {
     //Your code here
     vector<int>ans;
     if(root1==NULL || root2==NULL)
     return ans;
     unordered_map<int,int>ump;
     inorder(root1, ump, ans);
     inorder(root2,ump,ans);
     return ans;
     
    }
};
