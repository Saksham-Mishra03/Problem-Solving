//this question is basically find number  of connected components.

class Solution {
public:
    void dfs(int i, vector<int>&visited, vector<vector<int>>& isConnected)
    {
        if(visited[i])
        return;

        visited[i] = 1;
        for(int j = 0;j<isConnected[i].size();j++)
        {
            if(!visited[j] && isConnected[i][j]==1)
            dfs(j,visited, isConnected);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = isConnected.size();
        int cnt = 0;
        vector<int>visited(n,0);
        // traverse on all the components
        for(int i =0;i<n;i++)
        {
            if(!visited[i])
            {
                cnt++;
                dfs(i,visited, isConnected);
            }
        }
        return cnt;
    }
};
