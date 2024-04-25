class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>>adj(n);
        for(auto x: pre)
        adj[x[1]].push_back(x[0]);

        vector<int>ind(n,0);
        for(int i =0;i<n;i++)
        {
            for(auto x:adj[i])
            ind[x]++;
        }
        queue<int>q;
        for(int i = 0;i<n;i++)
        {
            if(ind[i]==0)
            q.push(i);
        }

        int ct =0;
        while(!q.empty())
        {
            int f = q.front();
            q.pop();
            ct++;
            for(auto i:adj[f])
            {
                ind[i]--;
                if(ind[i]==0)
                q.push(i);
            }
        }
        if(ct==n)return true;
        return false;
    }
};
