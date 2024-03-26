class Solution{
  public:
    /*You are required to complete this function*/
    int getLevelDiff(Node *root)
    {
       //Your code here
       if(root==NULL)
       return 0;
       
       if(!root->left && !root->right)
       return root->data;
       
       int esum = 0;
       int osum = 0;
       bool os  = true;
       
       queue<Node*>q;
       q.push(root);
       q.push(NULL);
       
       while(!q.empty())
       {
           Node* temp = q.front();
           q.pop();
           
           if(temp)
           {
               if(temp->left)
               q.push(temp->left);
               
               if(temp->right)
               q.push(temp->right);
               
               if(os)
               osum += temp->data;
               
               else
               esum += temp->data;
           }
           else
           {
               if(!q.empty())
               {
                   q.push(NULL);
                   os = not(os);
               }
           }
       }
       return osum-esum;
    }
};
