
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int s, int e) {
        
        vector<vector<pair<int,double>>>adj(n);
        for(int i = 0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }

        vector<double>pro(n,0);
        priority_queue<pair<double,int>>pq;

        pro[s]=1;
        pq.push({1,s});

        while(!pq.empty())
        {
            auto f = pq.top();
            double p = f.first;
            int node = f.second;
            pq.pop();

            for(auto i: adj[node])
            {
                int adnode = i.first;
                double adp = i.second;
                if(p*adp >pro[adnode])
                {
                    pro[adnode] = p*adp;
                    pq.push({pro[adnode],adnode});
                }
            }
            
        }
        return pro[e];
    }
};
