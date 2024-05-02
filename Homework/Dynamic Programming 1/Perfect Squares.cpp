/*******************************recursion solution***********************************/
class Solution {
public:
    int numSquares(int n) {

        if(n<=0)
        return 0;

        int ans = INT_MAX;
        for(int i = 1;i*i<=n;i++)
        {
            ans = min(ans, 1 + numSquares(n-(i*i)));
        }
        return ans;
        
    }
};
/*******************************************recur+memo***********************************/
class Solution {
public:
    int helper(int n,vector<int>&dp)
    {
        if(n==0)
        return 0;
        if(dp[n]!=-1)
        return dp[n];

        int ans = INT_MAX;
        for(int i = 1;i*i<=n;i++)
        {
            ans =  min(ans,helper(n-(i*i),dp)+1);
        }
       return dp[n] = ans;
       
        
    }
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return helper(n,dp);
    }
};
/********************************************dp soln*******************************/
class Solution {
public:
    int numSquares(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int>dp(n+1,INT_MAX);
        dp[0] = 0;
        for(int i = 1;i<=n;i++)
        {
            
            for(int j = 1;j*j<=i;j++)
            {
                dp[i]= min(dp[i],1+dp[i-(j*j)]);
            }
            
        }
        return dp[n];
    }
};
