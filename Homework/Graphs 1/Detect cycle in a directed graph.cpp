
 bool checkdfs(int x, vector<int> adj[], vector<int>&vis,vector<int>&back)
    {
        vis[x] = 1;
        back[x] = 1;
        
        for(auto i: adj[x])
        {
            if(!vis[i])
            {
                if(checkdfs(i,adj,vis,back)) return true;
            }
            else if(back[i])//agr cycle hogi to back pe phhle se 1 pada hoga ar becose recursion bapas ni ja paega thats why bo 0(unvisited ) ni hoga
            return true;
        }
        back[x] = 0;
        return false;
        
    }
    bool isCyclic(int v, vector<int> adj[]) {
        // code here
        vector<int>vis(v,0);
        vector<int>back(v,0);
        
        for(int i = 0;i<v;i++){
            if(!vis[i])
            {
                if(checkdfs(i,adj,vis,back)) return true;
            }
        }
        return false;
    }
