class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<pair<int,int>>adj[n+1];
        for(auto i: times)
        {
            adj[i[0]].push_back({i[1],i[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        
        vector<int>ans(n+1,INT_MAX);
        ans[k] = 0;

        while(!pq.empty())
        {
            auto i= pq.top();
            int time = i.first;
            int node = i.second;
            pq.pop();

            for(auto j: adj[node])
            {
                int adtime = j.second;
                int adnode = j.first;

                if(time+adtime<ans[adnode])
                {
                    ans[adnode] = time+adtime;
                    pq.push({ans[adnode],adnode});
                }
            }
        }
        int res = -1;
        for(int i=1;i<=n;i++)
        res = max(ans[i],res);

        if(res==INT_MAX) return -1;
        return res;
        
    }
};
