/*----------------------recursion----------------------------------------
class Solution {
public:
    int helper(int i, int tar,vector<int>& coins,int n)
    {
        if(i==n)return 0;
        if(tar<0)return 0;
        if(tar==0)return 1;
        int inc= helper(i,tar-coins[i],coins,n);
        int exc = helper(i+1,tar,coins,n);
        return inc+exc;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return helper(0,amount,coins,n);
    }
};
---------------------------- recur+memo --------------------------------

class Solution {
public:
    int memo(int i, int tar,vector<int>& coins,int n,vector<vector<int>>&dp)
    {
        if(i==n)return 0;
        if(tar<0)return 0;
        if(tar==0)return 1;
        if(dp[i][tar]!=-1)return dp[i][tar];
        int inc= memo(i,tar-coins[i],coins,n,dp);
        int exc = memo(i+1,tar,coins,n,dp);
        return dp[i][tar] = inc+exc;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return memo(0,amount,coins,n,dp);
    }
};
---------------------tabulation---------------------------------------*/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        //dp[i] = no of ways to make amonnt i 
        for (int coin : coins) {
            for (int j = coin; j <= amount; j++) {
                dp[j] += dp[j - coin];
            }
        }
        
        return dp[amount];
    }
};
