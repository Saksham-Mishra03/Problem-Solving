class Solution {
public:
Node* dfs(Node* cur,unordered_map<Node*,Node*>& mp)
    {
        vector<Node*> adj;
        Node* clone=new Node(cur->val);
        mp[cur]=clone;
            for(auto it:cur->neighbors)
            {
                if(mp.find(it)!=mp.end()) 
                {
                    adj.push_back(mp[it]);
                }
                else
                    adj.push_back(dfs(it,mp));
            }
            clone->neighbors=adj;
            return clone;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mp;
        if(node==NULL)
            return NULL;
        return dfs(node,mp);
    }};
