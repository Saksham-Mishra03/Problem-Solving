class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        if(nums.size()==1)
        return nums[0];
        if(nums[0]!=nums[1])
        return nums[0];

        while(l<=r)
        {
            int mid = (l+r)/2;
            if(nums[mid-1]!=nums[mid] && nums[mid+1]!=nums[mid])
            return nums[mid];

           else if(nums[mid-1]==nums[mid])
            {
                int first = mid-1; //mid-1 is the first occurance
                if(first % 2==0)
                l = mid+1;
                else
                r = mid-2; //-2 islie krega kiuki hme relative order bhi maintain rakhna h
            }
            else
            {
                int first = mid; // mid is the first occurance
                if(first %2 ==0)
                l = mid+2;  //+2 islie krega kiuki hme even odd ka relative order bhi maintain rakhna h
                else
                r = mid-1;
            }
        }
        return -1;
    }
};
