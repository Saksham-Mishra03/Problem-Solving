class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    Node* LCA(Node* root, int a, int b)
    {
        if(root==NULL)
        return NULL;
        
        if(root->data==a ||root->data==b)
        return root;
        
        Node* lans = LCA(root->left, a,b);
        Node* rans = LCA(root->right, a,b);
        
        if(lans && rans)
        return root;
        
        if(lans)
        return lans;
        
        if(rans)
        return rans;
        
        return NULL;
    }
    
    int distance(Node* root, int a,int ans)
    {

        if(root==NULL)
        return -1;
        
        if(root->data==a)
        return ans;
        
        int l = distance(root->left,a,ans+1);
       int r = distance(root->right,a,ans+1);
        
        if(l!=-1)
        return l;
        else 
        return r;
    }
    
    int findDist(Node* root, int a, int b) {
        // Your code here
        root = LCA(root, a, b);
        
        int x = distance(root,a,0); 
        int y = distance(root,b,0);
        
        return x+y;
        
    }
};
