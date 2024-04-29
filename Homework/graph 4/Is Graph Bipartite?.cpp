class Solution {
public:
    bool check(int sv, vector<int>&color, vector<vector<int>>& graph)
    {
        queue<int>q;
        q.push(sv);
        color[sv] = 0;

        while(!q.empty())
        {
            int f = q.front();
            q.pop();

            for(auto i: graph[f])
            {
                //agr adjacent vertex ko color ni dia to use de do
                if(color[i]==-1)
                {
                    color[i] = !color[f];
                    q.push(i);
                }
                else //agr adjacent ko color dia h to check kro color same to ni h 
                {
                    if(color[i]==color[f])
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {

        int v= graph.size();
        vector<int>color(v,-1);
        //checking for connected components
        for(int i = 0;i<v;i++)
        {
            if(color[i]==-1)
            {
                if(check(i,color,graph)==false)
                return false;
            }
        }
        return true;
    }
};
