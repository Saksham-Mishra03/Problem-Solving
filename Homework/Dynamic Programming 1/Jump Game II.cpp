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




