/*----------------------------recursion-------------------------------
class Solution {
public:
    int helper(vector<vector<int>>& grid, int m, int n){
        if(m==0 && n==0)return grid[0][0];
        if(m<0 || n<0)return INT_MAX;
        return min(helper(grid, m-1, n),helper(grid, m, n-1))+grid[m][n];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        return helper(grid, m-1, n-1);
        
    }
};

----------------------------memo---------------------------------------
class Solution {
public:
    int helper(vector<vector<int>>& grid, int m, int n,vector<vector<int>>& dp){
        if(m==0 && n==0)return grid[0][0];
        if(m<0 || n<0)return INT_MAX;
        if(dp[m][n]!=-1)return dp[m][n];
        return dp[m][n] = min(helper(grid, m-1, n,dp),helper(grid, m, n-1,dp))+grid[m][n];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return helper(grid, m-1, n-1,dp);
        
    }
};
---------------------------tabulation--------------------------------*/
//dp approach


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        vector <vector <int>> dp(r, vector <int>(c, 0));
        dp[0][0] = grid[0][0];
        
        for (int i = 1; i < c; i++) {
            dp[0][i] = grid[0][i] + dp[0][i - 1];
        }
        
        for (int i = 1; i < r; i++) {
            dp[i][0] = grid[i][0] + dp[i - 1][0];
        }

        for (int i = 1; i < r; i++) {
            for (int j = 1; j < c; j++) {
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[r - 1][c - 1];
    }
};


