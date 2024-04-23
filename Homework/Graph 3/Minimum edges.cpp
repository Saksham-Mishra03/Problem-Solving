        int minimumEdgeReversal(vector<vector<int>> &edges,int n,int src,int dst)
        {
            
            vector<vector<pair<int,int>>>adj(n+1); // isme pair represent krega har node ko and us tk pahuchne ka edge ka direction in other words distance and becose ye ek adjacency matrix h so there will ve vector of nodes
            for(auto i:edges)
            {
                int u = i[0]; // bha u->v ek edge uthai
                int v = i[1];
                
                adj[u].push_back({v,0});
                adj[v].push_back({u,1});
            }
            
            deque<pair<int,int>>dq;
            vector<int>dist(n+1, INT_MAX);
            
            dq.push_back({src,0});
            dist[src]=0;
            
            while(!dq.empty()){
                auto f = dq.front();
                int node = f.first;
                int edg = f.second;
                dq.pop_front();
                
                if(node==dst)
                return edg;
                
                for(auto i: adj[node])
                {
                    int neigh  = i.first;
                    int edgdir = i.second;
                    
                    if(dist[neigh]>dist[node]+edgdir){
                    
                        dist[neigh] = dist[node]+ edgdir;
                        
                    if(edgdir)
                    dq.push_back({neigh, dist[neigh]});
                    
                    else
                    dq.push_front({neigh, dist[neigh]});
                    }
                }
                
                
            }
            return -1;
        }
