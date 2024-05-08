class Solution {
public:
    void initialize(vector<int>&parent, vector<int>&rank, int n)
    {
        for(int i = 0;i<=n;i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }

    }
        int find(vector<int>&parent,int x)
    {
        if(parent[x]==x)return x;
        int p = find(parent, parent[x]); //ulitmate parent
        parent[x] = p;
        return p;
    }
    void unioinset( vector<int>&parent,int u,int v, vector<int>&rank){
	    u=find(parent,u);
	    v=find(parent,v);
	    if(rank[u]>rank[v]){
	        parent[v]=u;
	    }
	    else if(rank[u]<rank[v]){
	        parent[u]=v;
	    }
        else{
            parent[v]=u;
            rank[u]++;
        }
	}
    vector<int>edge;
    bool checkDSU(vector<vector<int>>& edges, int n, vector<int>& blacklist,vector<int>&parent,vector<int>&rank){

        
        for(int i=0; i < edges.size(); i++){
            if(blacklist.size()>0 && edges[i]==blacklist)
                continue;
            
            if(find(parent,edges[i][0]) == find(parent,edges[i][1])){
                edge = edges[i];
                return true;
            }
            else
                unioinset(parent,edges[i][0], edges[i][1],rank);
        }
        return false;
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>parent(n+1),rank(n+1),indegree(n+1,-1);
        initialize(parent,rank,n);

        for(int i=0;i<n;i++){
            if(indegree[edges[i][1]]!=-1){
                vector<int> black = edges[i];
                if(checkDSU(edges, n, black,parent,rank))
                    return edges[indegree[edges[i][1]]];
                else
                    return black;
            }else{
                indegree[edges[i][1]] = i;
            }
        }
        vector<int> noblack;
        checkDSU(edges,n,noblack,parent,rank);
        return edge;    
    }
};
