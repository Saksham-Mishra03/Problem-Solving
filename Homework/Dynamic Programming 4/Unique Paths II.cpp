/*--------------------------------------recursion----------------------------------------

class Solution {
public:
    int helper(int i, int j, int m,int n, vector<vector<int>>ob){
        if(ob[i][j]==1)return 0;
        if(i==m-1 && j==n-1)return 1;
        int cnt = 0;
        if(i+1<m && ob[i+1][j]==0)
        cnt += helper(i+1, j, m, n, ob);
        if(j+1<n && ob[i][j+1]==0)
        cnt += helper(i, j+1, m, n, ob);
        return cnt;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& ob) {
        int m = ob.size();
        int n = ob[0].size();
        return helper(0,0,m,n,ob);
    }
};
--------------------------------recursio+memo--------------------------------------
class Solution {
public:
    int helper(int i, int j, int m,int n, vector<vector<int>>&ob,vector<vector<int>>&dp){
        if(ob[i][j]==1)return 0;
        if(i==m || j==n) return 0;
        if(i==m-1 && j==n-1)return 1;
        if(dp[i][j]!=-1 && ob[i][j]==0)return dp[i][j];
        int cnt = 0;
        if(i+1<m && ob[i][j]==0)
        cnt += helper(i+1, j, m, n, ob,dp);
        if(j+1<n && ob[i][j]==0)
        cnt += helper(i, j+1, m, n, ob,dp);
        return dp[i][j] = cnt;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& ob) {
        int m = ob.size();
        int n = ob[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return helper(0,0,m,n,ob,dp);
    }
};
---------------------------------tabulation------------------------------------------*/
class Solution {
public:

    /*
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int m = o.size();
        int n = o[0].size();

        int dp[m+1][n+1]; 

        //filling 1st row
        int flag1 = 0;
        for(int i = 0;i<=n;i++)
        {
            if(o[0][i] ==1)
            {
                flag1 = 1;
            }
            if(flag1 == 1)
            {
                dp[0][i] = -1; 
            }
            else
            {
                dp[0][i] = 1;
            }
        }

        //filling 1st column
        int flag2 = 0;
        for(int i = 0;i<=m;i++)
        {
            if(o[i][0] ==1)
            {
                flag2 = 1;
            }
            if(flag2 == 1)
            {
                dp[i][0] = -1; 
            }
            else
            {
                dp[i][0] = 1;
            }
        }
        for(int i = 1;i<m;i++)
        {
            for(int j = 1;j<n;j++)
            {
                if(o[i][j]==1)
                dp[i][j] = -1;
                else if(dp[i-1][j]==-1 && dp[i][j-1]==-1)
                dp[i][j] = -1;
                else if(dp[i-1][j]==-1)
                dp[i][j] = dp[i][j-1];
                else if(dp[i][j-1]==-1)
                dp[i][j] = dp[i-1][j];
                else
                dp[i][j] = dp[i-1][j]+dp[i][j-1];

            }
        }
        return dp[m-1][n-1];

    }
*/
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(); 
        int n = obstacleGrid[0].size(); 
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        //there's only one way to start, set dp[0][1] to 1.
        dp[0][1] = 1;
        
        // Iterate through the grid to fill in the dp array
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (obstacleGrid[i - 1][j - 1]==0) { // If the current cell is not an obstacle
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};
