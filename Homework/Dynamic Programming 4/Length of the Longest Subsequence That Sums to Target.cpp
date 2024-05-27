/*-----------------------------recursion soln----------------------------------
class Solution {
public:
    int helper(int i, vector<int>&nums, int target,int n){
        if(target==0)return 0;
        if(i>=n)return -1e9 ;

        int inc = -1e9;
        if(target>=nums[i])
        inc = 1+ helper(i+1, nums, target-nums[i], n);
        int exc =  helper(i+1,nums,target,n);
        return max(inc,exc);
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int ans =  helper(0,nums,target, nums.size());
        if(ans<0) return -1;
        else
        return ans;

    }
};

---------------------------------recur+memo------------------------------------
class Solution {
public:
    int helper(int i, vector<int>&nums, int target,int n,vector<vector<int>>&dp){
        if(target==0)return 0;
        if(i>=n)return -1e9 ;

        if(dp[i][target]!=-1)return dp[i][target];

        int inc = -1e9;
        if(target>=nums[i])
        inc = 1+ helper(i+1, nums, target-nums[i], n,dp);
        int exc =  helper(i+1,nums,target,n,dp);
        return dp[i][target] =  max(inc,exc);
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        int ans =  helper(0,nums,target, nums.size(),dp);
        if(ans<0) return -1;
        else
        return ans;
    }
};

--------------------------------tabulation-------------------------------*/

class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));

        for(int i = 0;i<=nums.size();i++)
        dp[i][0] = 0;

        for(int i = 1; i <= nums.size(); i++) {
            for(int j = 1; j <= target; j++) {
                dp[i][j] = dp[i-1][j]; 
                if(nums[i-1] <= j) {
                    if(dp[i-1][j - nums[i-1]] != -1) {
                        dp[i][j] = max(dp[i][j], 1 + dp[i-1][j - nums[i-1]]);  
                    }
                }
            }
        }

        return dp[nums.size()][target];
    }
};
