class DSU{
    vector<int>parent,rank;
    public:
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n,0);
        for(int i = 0;i<n;i++)
            parent[i]=i;
    }
    int find(int x)
    {
        if(parent[x]==x)return x;
        int p = find(parent[x]);
        parent[x] = p;
        return p;
    }
    void unionfind(int u,int v)
    {
        int pu = find(u);
        int pv  = find(v);
        if(pu !=pv)
        {
            if(rank[pu]<rank[pv])
            parent[pu] = pv;
            else if(rank[pv]<rank[pu])
            parent[pv] = pu;
            else
            {
                parent[pv] = pu;
                rank[pu]++;
            }
        }
    }
};
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        DSU ob(n);
        for(int i = 0;i<n;i+=2)//initiallyy sare alternating ko connect krke 1-1 componenet bna do
            ob.unionfind(row[i],row[i+1]);

        int ans =0;
        //now checkk agr connected bale couple bn skte agr nhi toh couple i,i+1 bale ko connect kro becose bahi couple h
        for(int i = 0;i<n;i+=2)
        {
            if(ob.find(i)!=ob.find(i+1))
            {
                ob.unionfind(i,i+1);
                ans++;
            }
        }
        return ans;
    }
};
