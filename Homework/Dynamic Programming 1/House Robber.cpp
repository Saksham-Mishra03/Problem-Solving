/********************************************Recur+memo****************************************/
class Solution {
public:
    int helper(vector<int>& nums, int i,int n,vector<int>&dp)
    {
        if(i>=n)
        return 0;

        if(dp[i]!=-1)
        return dp[i];

        int inc = nums[i] + helper(nums, i+2,n,dp);
        int exc = helper(nums, i+1,n,dp);
        return dp[i] = max(inc,exc);
    } 
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp(n+1,-1);
        return helper(nums,0,n,dp);
    }
};
/****************************************tabulation******************************************/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n =nums.size();

    if (n == 1)
    {
        return nums[0];
    }
    vector<int>dp(n);
    dp[0] = nums[0];
    if (n > 1)
    {
        dp[1] = max(nums[0], nums[1]);
    }
    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    }
    int ans = dp[n - 1];

    return ans;
        
    }
};
