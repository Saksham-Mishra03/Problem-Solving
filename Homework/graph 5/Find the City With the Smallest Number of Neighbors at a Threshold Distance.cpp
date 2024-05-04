class Solution {
public:
    void floyd(vector<vector<int>>&mat, int n)
    {
        for(int k = 0; k<n;k++)
        {
            for(int i = 0;i<n;i++)
            {
                for(int j = 0;j<n;j++)
                {
                    mat[i][j] = min(mat[i][j], (mat[i][k]+mat[k][j]));
                }
            }
        }
       // return mat;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int T) {

        vector<vector<int>>mat(n,vector<int>(n,1e5));
        for(auto i:edges)
        {
            mat[i[0]][i[1]] = i[2];
            mat[i[1]][i[0]] = i[2];
        }

        for (int i = 0; i < n; i++) 
            mat[i][i] = 0;
        

        floyd(mat, n);

        

        int cityMax = n;
        int cityNo = -1;

        for(int i=0;i<n;i++) {
            int count=0;
            for(int j=0;j<n;j++) {
                if(mat[i][j] <= T) {
                    count++;
                }
            }
            if(count <= cityMax) {
                cityMax = count;
                cityNo = i;
            }

        }

        return cityNo;

    }
};
