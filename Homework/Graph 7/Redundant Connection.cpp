class Solution {
public:

    void initialise(vector<int>&parent,vector<int>&rank,int n)
    {
        	for(int i=0;i<=n;i++){
	        parent[i]=i;
	        rank[i]=0;
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>parent(n+1),rank(n+1);
        initialise(parent,rank,n);
        vector<int>ans;
        for(auto i:edges)
        {
            int x = i[0];
            int y = i[1];
            int px = find(parent,x);
            int py = find(parent,y);

            if(px!=py)
            {
                unioinset(parent,x,y,rank);
            }
            else{    
            ans.push_back(x);
            ans.push_back(y);
            }
        }
        return ans;
        
    }
};
