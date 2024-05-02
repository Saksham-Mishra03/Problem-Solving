class Solution {
public:
    int helper(vector<int>& nums) {
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

    int rob(vector<int>& nums) {

        int n = nums.size();
        if(n==1)
        return nums[0];
        vector<int>temp1,temp2;
        for(int i = 0;i<n;i++)
        {
            if(i>0)
            temp1.push_back(nums[i]);

            if(i!=n-1)
            temp2.push_back(nums[i]);
        }
        return max(helper(temp1),helper(temp2));
    }
};
