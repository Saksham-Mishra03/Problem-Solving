/*------------------------------recursion soln-------------------------------
class Solution {
public:
    int helper(vector<int>& coins, int amt, int i)
    {
        if(i==0){
            if(amt%coins[i]==0)return amt/coins[i];
            else return 1e9;
        }

        int exc = helper(coins,amt,i-1);
        int inc = INT_MAX;
        if(coins[i]<=amt)
        {
            inc = 1+helper(coins,amt-coins[i],i);
        }
        return min(exc,inc);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans= helper(coins,amount,n-1);
        if(ans==1e9)return -1;
        return ans;
    }
};
---------------------------recur+memo-------------------------------
class Solution {
public:
    int helper(vector<int>& coins, int amt, int i,vector<vector<int>> &dp)
    {
        if(i==0){
            if(amt%coins[i]==0)return amt/coins[i];
            else return 1e9;
        }
        if(dp[i][amt] != -1)return dp[i][amt];

        int exc = helper(coins,amt,i-1,dp);
        int inc = INT_MAX;
        if(coins[i]<=amt)
        {
            inc = 1+helper(coins,amt-coins[i],i,dp);
        }
        return dp[i][amt] = min(exc,inc);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        int ans= helper(coins,amount,n-1,dp);
        if(ans==1e9)return -1;
        return ans;
    }
};
---------------------------tabulation----------------------------------*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1));

        //dp[i][j] = minimum number of coins needed to make amount j  when till ith count is used

        for(int j = 0;j<=amount;j++)
        {
            if(j%coins[0]==0) 
            dp[0][j]=j/coins[0];
            else dp[0][j] = 1e9;
        }

        for(int i = 1;i<n;i++)
        {
            for(int j =0;j<=amount;j++)
            {
                int exc = dp[i-1][j];
                int inc = INT_MAX;
                if(coins[i]<=j)
                inc = 1+ dp[i][j-coins[i]];
                dp[i][j] = min(inc,exc);
            }
        }
        int ans = dp[n-1][amount];
        if(ans==1e9)return -1;
        return ans;
    }
};
