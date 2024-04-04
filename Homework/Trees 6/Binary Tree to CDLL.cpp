class Solution
{
  public:
    //Function to convert binary tree into circular doubly linked list.
    Node *solve(Node *root, Node* &head, Node* &prev)
    {
        if(root==NULL)
        return root;
        
        solve(root->left,head,prev);
        if(prev ==NULL)
        head = root;
        else
        {
            root->left = prev;
           prev->right = root;
        }
        prev = root;
        solve(root->right,head,prev);
        
        
        prev->right = head;
        head->left = prev;
        
        return head;
    }
    Node *bTreeToCList(Node *root)
    {
    //add code here.
        Node * head = NULL;
        Node * prev = NULL;
        
        return solve(root, head, prev);
    }
};
