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

/************************tabulation*************************/
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = size(nums);
        vector<int> dp(n, 10001);
        dp[n - 1] = 0;  
        for(int i = n - 2; i >= 0; i--) {
            for(int j = 1+i; j <= min(n-1, i+nums[i]); j++) {
                dp[i] = min(dp[i],1+dp[j]); 
            }
        }

	return dp[0];
    }
};

//TC: O(N2)
//space: O(n)
/*************************************************************/






