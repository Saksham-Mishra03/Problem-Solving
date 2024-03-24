class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        
        vector<int>ans;
        if(root==NULL)
        return ans;
        
        map<int,int>nodes; //hd and us hd pe last value
        queue<pair<Node*, int>>q;  //node and uska hd;
        
        q.push({root, 0});
        
        while(!q.empty())
        {
            pair<Node*, int>fn = q.front();
            q.pop();
            Node* f = fn.first;
            int hd = fn.second;
            
            nodes[hd] = f->data;
            
            if(f->left)
            {
                q.push({f->left,hd-1});
            }
            if(f->right)
            {
                q.push({f->right,hd+1});
            }
        }
        for(auto i: nodes)
        ans.push_back(i.second);
        
        return ans;
        
    }
};
