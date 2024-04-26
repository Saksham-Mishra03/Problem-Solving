class Solution {
public:
    void dfs(int sv, vector<int>adj[],vector<int>&visited)
    {
        visited[sv] = true;
        for(int i: adj[sv])
        {
            if(visited[i])continue;
            dfs(i,adj,visited);
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(auto i:edges)
        {
            adj[i[0]].push_back(i[1]);
        }
        vector<vector<int>>ans(n);

        for(int i = 0;i<n;i++)
        {
            vector<int>visited(n,false);
            dfs(i,adj,visited);
            for(int j = 0;j<n;j++)
            {
                if(i==j)continue;
                if(visited[j])
                ans[j].push_back(i);
            }
        }
        return ans;
    }
};
