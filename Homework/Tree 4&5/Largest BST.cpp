class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    
    class NodeInfo{
    public: 
    
    bool isBST;
    int minElement;
    int maxElement;
    int size;
    
    NodeInfo(bool is, int mini, int maxi, int s){
        isBST = is;
        minElement = mini;
        maxElement = maxi;
        size = s;
    }
    };
    
    NodeInfo* helper(Node* root){
        if(root==NULL)
        return new NodeInfo(true, INT_MAX, INT_MIN, 0);
        
        NodeInfo* lefttree = helper(root->left);
        NodeInfo* righttree = helper(root->right);
        
        NodeInfo* rootInfo = new NodeInfo(true, INT_MAX, INT_MIN, 0);
       
        
        rootInfo->isBST = lefttree->isBST && righttree->isBST && (root->data>lefttree->maxElement) && (root->data<righttree->minElement);
        
        rootInfo->minElement = min(root->data,lefttree->minElement);
        rootInfo->maxElement = max(root->data,righttree->maxElement);
        
        if(rootInfo->isBST)
        {
            rootInfo->size = lefttree->size+righttree->size+1;
        }
        else
        {
            rootInfo->size = max(lefttree->size,righttree->size);
        }
        return rootInfo;
    }
    
    int largestBst(Node *root)
    {
    	//Your code here
    	return helper(root)->size;
    }
};
