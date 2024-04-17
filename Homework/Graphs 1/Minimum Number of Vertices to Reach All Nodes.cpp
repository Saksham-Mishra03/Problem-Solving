class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<int>ind(n,0);
        for(auto i:edges)
        {
            ind[i[1]]++;
        }
        vector<int>ans;
        for(int i = 0;i<n;i++)
        {
            if(ind[i]==0)
            ans.push_back(i);
        }
        return ans;
    }
};
