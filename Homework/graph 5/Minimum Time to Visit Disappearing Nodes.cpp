class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        //making adjacency matrix
        vector<pair<int, int>> adj[n];

        for (auto x : edges) {
            adj[x[0]].push_back({x[1], x[2]});
            adj[x[1]].push_back({x[0], x[2]});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>time(n,INT_MAX);

        time[0] = 0;
        pq.push({0,0});

        while(!pq.empty())
        {
            auto f = pq.top();
            int wt = f.first;
            int node = f.second;
            pq.pop();

            if(time[node]<wt)continue;

            for(auto i: adj[node])
            {
                int adnode = i.first;
                int adwt = i.second;

                if(wt+adwt<time[adnode] && wt+adwt<disappear[adnode])
                {
                    time[adnode] = wt+adwt;
                    pq.push({time[adnode],adnode});
                }
            }
        }
        for(int i = 0;i<n;i++)
            if(time[i]==INT_MAX)
                time[i] = -1;

        return time;
    }
};
