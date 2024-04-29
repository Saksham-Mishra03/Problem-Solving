/************** recursion solution****************/

class Solution {
public:
    
    int recur(vector<int>& nums, int target, int i)
    {
        if(i>=target)
        return 0;
        int cnt = 100001;
        for(int j = 1;j<=nums[i];j++)
        {
            cnt = min(cnt, 1+ recur(nums,target, i+j));
        }
        return cnt;

    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        return recur(nums,n-1, 0);
    }
};

//TC: O(!N*max(a[n]))
//space: o(n)

/***************************************************/

/***********************recur+memo*****************/
class Solution {
public:
    
    int recur(vector<int>& nums, int target, int i,vector<int>&dp)
    {
        if(i>=target)
        return 0;

        if(dp[i]!=-1)
        return dp[i];

        int cnt = 100001;
        for(int j = 1;j<=nums[i];j++)
        {
            cnt = min(cnt, 1+ recur(nums,target, i+j,dp));
            dp[i] = cnt;
        }
        return cnt;

    }
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>dp(n,-1);
        return recur(nums,n-1, 0,dp);
    }
};


//TC: O(n2)
//space: o(n)

/****************************************************************************/






