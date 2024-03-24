class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int>ans;
        if(root==NULL)
        return ans;
        
        map<int,int>mp; //1st int hd, 2nd int node->data
        queue<pair<Node*,int>>q; // node, uska hd
        
        q.push(make_pair(root,0));
        
        while(!q.empty())
        {
            pair<Node*,int>temp = q.front();
            q.pop();
            
            Node* f = temp.first;
            int hd = temp.second;
            
            if(mp.find(hd)==mp.end()) //only top element of every hd is insertted so if phle se element h to ar mt dalo
            {
                mp[hd] = f->data;
            }
            
            if(f->left)
            q.push(make_pair(f->left,hd-1));
            
            if(f->right)
            q.push(make_pair(f->right,hd+1));
        }
        
        for(auto i: mp)
        {
            ans.push_back(i.second);
        }
        return ans;
    }

};
