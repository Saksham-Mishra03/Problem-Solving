class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1)
        return nums[0];

        int l = 0;
        int r = nums.size()-1;

        if(nums[l]<nums[r])
        return nums[l];
        int ans = -1;

        while(l<r)
        {
            int mid  =  (l+r)/2;
            if(nums[mid]>nums[mid+1])
            {
                ans = mid+1;
                break;   
            }
            else if(nums[mid]>nums[r])//we are in 1st part
            {
                l = mid+1;
            }
            else//we are in seconnd part 
            {
               r=mid;
            }
        }
        return nums[ans];
    }
};
