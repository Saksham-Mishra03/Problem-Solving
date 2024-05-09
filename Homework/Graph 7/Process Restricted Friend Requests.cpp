class Solution {
public:
    vector<int>parent,rank;
    void initialise(int n)
    {
            parent.resize(n);
            rank.resize(n);
        	for(int i=0;i<n;i++){
	        parent[i]=i;
	        rank[i]=0;
	    }
    }
    int find(int x)
    {
        if(parent[x]==x)return x;
        int p = find(parent[x]); //ulitmate parent
        parent[x] = p;
        return p;
    }
    void unioinset(int u,int v){
	    u=find(u);
	    v=find(v);
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
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        initialise(n);
        vector<bool>ans;

        for(auto i:requests)
        {
            int flag = 0;
            int x = find(i[0]);
            int y = find(i[1]);

            for(auto j : restrictions)
            {
                int u = find(j[0]);
                int v = find(j[1]);

                if((x==u && y==v)||(x==v && y==u))
                {
                    flag++;
                    break;
                }
            }
            if(flag==1)
            ans.push_back(false);
            else{
                ans.push_back(true);
                unioinset(x,y);
            }
        }
        return ans;
    }
};
