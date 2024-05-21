/* ---------------------------------recursion------------------------------------------
class Solution {
public:
    int helper(int x, int y, int m, int n)
    {
        if(x==m-1 && y==n-1)return 1;
        int cnt = 0;
        if(x+1<m)
        cnt += helper(x+1,y,m,n);
        if(y+1<n)
        cnt += helper(x,y+1,m,n);
        return cnt;
    }
    int uniquePaths(int m, int n) {
        return helper(0,0,m,n);
    }
};

-----------------------------------------recursion+memo------------------------------------
class Solution {
public:
    int helper(int x, int y, int m, int n,vector<vector<int>>&dp)
    {
        if(dp[x][y]!=-1)return dp[x][y];
        if(x==m-1 && y==n-1)return 1;
        int cnt = 0;
        if(x+1<m)
        cnt += helper(x+1,y,m,n,dp);
        if(y+1<n)
        cnt += helper(x,y+1,m,n,dp);
        return dp[x][y] = cnt;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return helper(0,0,m,n,dp);
    }
};

-------------------------------------tabulation--------------------------------------*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        //fill first row with 1
        for(int i = 0;i<=n;i++)
        dp[0][i] = 1;

        //fill first column with 1
        for(int i = 0;i<=m;i++)
        dp[i][0] = 1;

        //filling rest matrix
        for(int i = 1;i<m;i++){
            for(int j = 1;j<n;j++){
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
