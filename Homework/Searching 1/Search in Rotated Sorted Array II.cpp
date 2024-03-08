

        class Solution {
public:
    int search(vector<int>& nums, int target) {

        int l = 0;
        int r = nums.size()-1;
        while(l<=r)
        {
            int mid  = (r+l)/2;
            if(nums[mid]==target)
            return true;

             if((nums[l] == nums[mid]) && (nums[r] == nums[mid]))
            {
                l++;
                r--;
            }

           
            else if(nums[l]<=nums[mid])
            {
                if(target >= nums[l] && target <= nums[mid])
                r = mid-1;

                else
                l = mid+1;
            }
            else
            {
                if(target>=nums[mid]&& target<= nums[r])
                l = mid+1;
                else
                r = mid-1;
            }



        }
        return false;

        
    }
};
        
    
