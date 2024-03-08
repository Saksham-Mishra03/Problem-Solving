class Solution {
public:


    vector<int> searchRange(vector<int>& nums, int target) {
    vector<int>ans;
    int a=-1;
    int b = -1;
    if((int)nums.size()==1&&target == nums[0])
    {
        a = 0;
        b = 0;
    }
    int u = nums.size()-1;
    int l = 0;
      while(u>=l)
            {
            int mid = l+(u-l)/2;
            if(target==nums[mid])
            {
                a=mid;
                u= mid-1;
              
            }
            
            else if(target>nums[mid])
            l = mid+1;
            else if(target<nums[mid])
            u =  mid-1;  
            }
            
            
             u = nums.size()-1;
             l = 0;
            while(u>=l)
            {
            int mid = l+(u-l)/2;
            if(target==nums[mid])
            {
                b=mid;
                l= mid+1;
              
            }
            
            else if(target>nums[mid])
            l = mid+1;
            else if(target<nums[mid])
            u =  mid-1;  
            }

            
            ans.push_back(a);
            ans.push_back(b);


   
        return ans;
    }
};
