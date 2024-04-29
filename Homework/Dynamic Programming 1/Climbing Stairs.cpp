class Solution {
public:

//memoization solution
/*
    int helper(vector<int>&dp,int n)
    {
        if(n==0)
        return 1;
        if(n==1||n==2)
        return n;

        if(dp[n]!=-1)
        return dp[n];

        dp[n]= helper(dp,n-1)+helper(dp,n-2);
        return dp[n];

    }
    int climbStairs(int n) {

        vector<int>dp(n+1,-1);
       return helper(dp,n);
        
    }
*/

//dp approach
    int climbStairs(int n) {

        if(n<=2)
        return n;
        vector<int>dp(n+1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;

        for(int i=3;i<=n;i++)
        dp[i]=dp[i-1]+dp[i-2];

        return dp[n];
        
    }
};
