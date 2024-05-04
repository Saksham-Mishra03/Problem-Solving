class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int,int>>>adj(n);
        for(auto i: flights)
        {
            adj[i[0]].push_back({i[1],i[2]});
        }
        vector<int>ans(n,INT_MAX);
        
        priority_queue<pair <int,pair<int,int>>,vector<pair <int,pair<int,int>>>,             greater<pair<int,pair<int,int>>>>pq; //1st k, 2nd cost, third dest

        pq.push({0,{0,src}});
        ans[src] = 0;

        while(!pq.empty())
        {
            auto f = pq.top();
            int kk = f.first;
            int  cost= f.second.first;
            int d = f.second.second;
            pq.pop();

            if(kk>k)
            break;

            for(auto j:adj[d])
            {
                int adnode = j.first;
                int adcost = j.second;

                if(ans[adnode]>adcost+cost && kk<=k){
                    ans[adnode] = adcost+cost;
                    pq.push({kk+1,{ans[adnode],adnode}});
                }
            }
        }
        if(ans[dst]==INT_MAX)return -1;
       return ans[dst];
        
    }
};
