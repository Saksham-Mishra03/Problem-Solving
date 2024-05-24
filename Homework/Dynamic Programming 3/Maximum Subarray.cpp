/*-------------------------dp solution-------------------------------
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,0);
        //at any point of time either we can continue with same subarray or start new one
        //dp[i] = max sum till i

        dp[0] = nums[0];
        int ans = nums[0];
        for(int i = 1;i<n;i++){
            dp[i] = max(dp[i-1]+nums[i],nums[i]);
            ans = max(dp[i],ans);
        }
        return ans;
    }
};
-------------------------kadane(space obti. dp)------------------------*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int prev = nums[0];
        int ans = nums[0];
        for(int i = 1;i<n;i++){
            int cur = max(prev+nums[i],nums[i]);
            ans = max(cur,ans);
            prev = cur;
        }
        return ans;
    }
};
