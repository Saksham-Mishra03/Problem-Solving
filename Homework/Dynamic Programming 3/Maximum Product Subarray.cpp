/*--------------------------------dp soln--------------------------------

class Solution {
public:
    int maxProduct(vector<int>& nums) {
                int n = nums.size();
        vector<vector<int>>dp(n , vector<int>( 2, nums[0]));

        //we will have dp of 2 columns. where dp[i][0] will hold maximum value, dp[i][1] will have mini, since -ve*-ve = +ve so both required 

        int ans = nums[0];
        for(int i = 1;i<n;i++){
            dp[i][0] = max(dp[i-1][0]*nums[i], max(dp[i-1][1]* nums[i], nums[i]));
            dp[i][1]=min(dp[i-1][0]*nums[i] , min( dp[i-1][1]*nums[i],nums[i]));
            ans = max(ans , max(dp[i][1] , dp[i][0]));
        }
        return ans;
    }
};

---------------------kadanes updated soln ----------------------------*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int current =1;
        int maxi=INT_MIN;
        
        for (int i=0; i<nums.size(); i++){
            current*=nums[i];
            if (current>maxi){
                maxi=current;
            }
            if (current==0){
                current=1;
            }
        }
        current=1;
        for (int i=nums.size()-1; i>=0; i--){
            current*=nums[i];
            if (current>maxi){
                maxi=current;
            }
            if (current==0){
                current=1;
            }
        }
        return maxi;
    }
};
