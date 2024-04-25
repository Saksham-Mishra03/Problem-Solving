class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int>indegree(n,0);

        vector<int>adj[n];
        for(auto it:pre){
            adj[it[1]].push_back(it[0]);
        }

        for(int i = 0;i<n;i++)
        {
            for(auto j:adj[i])
            indegree[j]++;
        }
        queue<int>q;
        for(int i = 0;i<n;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }

        vector<int>ans;
        while(!q.empty())
        {
            int f = q.front();
            q.pop();
            ans.push_back(f);

            for(auto i: adj[f])
            {
                indegree[i]--;
                if(indegree[i]==0)
                q.push(i);
            }
        }
        if(ans.size()==n)
        return ans;
        return {};
    }
};
