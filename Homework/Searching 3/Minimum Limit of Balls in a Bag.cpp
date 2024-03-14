#define ll long long int
class Solution {
public:

    bool candivide(vector<int>&nums,int balls,int n, int maxop)
    {
        int cnt = 0;
        for(ll i = 0;i<n;i++)
        {    
            if(nums[i]>balls)
            {
                cnt+= (nums[i]-1)/balls; //agr balls jada h mid bali penalty se to divide kro and -1 islie kiuki 1 element phle se tha to result 1 km rhega
            }
        }
        return maxop>=cnt;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        ll l = 1;
        ll h = *max_element(nums.begin(),nums.end());
        ll n = nums.size();

        ll ans;
        while(l<=h)
        {
            ll mid = (l+h)/2;
            if(candivide(nums,mid,n,maxOperations))
            {
                ans = mid;
                h = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        return ans;
    }
};
