class Solution {
public:
    void initialise(vector<int>&parent,vector<int>&rank,int n)
    {
        	for(int i=0;i<=n;i++){
	        parent[i]=i;
	        rank[i]=0;
	    }
    }
    int find(vector<int>&parent, int x)
    {
        if(parent[x]==x)return x;
        int p = find(parent,parent[x]);
        parent[x]=p;
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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int>parent1(n+1),rank1(n+1);
        vector<int>parent2(n+1),rank2(n+1);
        int c=0; // c is removed edges
        initialise(parent1,rank1,n);
        initialise(parent2,rank2,n);

        int p1 = 0; // store count of remaining edges in p1 graph
        int p2 = 0; // store count of remaining edges in p2 graph

//sare edges pe traverse kro and dhuno phle both >alice>bob
        for(int i=0;i<edges.size();i++){
            if(edges[i][0]==3){
                //agr same component me nahi to unioun krdo and c ko bada do 
                if(find(parent1,edges[i][1])!=find(parent1,edges[i][2])){
                    unioinset(parent1,edges[i][1],edges[i][2],rank1);
                    p1++; 
                }
                if(find(parent2,edges[i][1])!=find(parent2,edges[i][2])){
                    unioinset(parent2,edges[i][1],edges[i][2],rank2);
                    p2++;
                }
                else c++;
            }
        }

        for(int i=0;i<edges.size();i++){
            if(edges[i][0]==1){
                //same for alice
                if(find(parent1,edges[i][1])!=find(parent1,edges[i][2])){
                    unioinset(parent1,edges[i][1],edges[i][2],rank1);
                    p1++;
                }
                else{
                    c++;
                }
            }
            else if(edges[i][0]==2){
                //same for bob
                if(find(parent2,edges[i][1])!=find(parent2,edges[i][2])){
                    unioinset(parent2,edges[i][1],edges[i][2],rank2);
                    p2++;
                }
                else{
                    c++;
                }
            }
        }
        if(p1==n-1 && p2==n-1) return c;
        return -1;
    }

};
