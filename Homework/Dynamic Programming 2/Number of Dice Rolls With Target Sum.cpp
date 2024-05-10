#define ll long long int
#define m  1000000007

/*-------------------------recursion solution----------------------------
class Solution {
public:
    ll helper(int dice, int face, int tar)
    {
        //base cases
        if(tar<0)return 0;
        if(dice==0 && tar!=0)return 0;
        if(dice!=0 && tar==0) return 0;
        if(dice==0 && tar==0) return 1;

        ll sum = 0;
        for(int i = 1;i<=face;i++)
        {
            sum+= helper(dice-1,face,tar-i);
        }
        return sum;
    }
    int numRollsToTarget(int n, int k, int target) {
        return helper(n,k,target);
    }
};

------------------------------recur+memo ------------------------------
class Solution {
public:
    ll helper(int dice, int face, int tar,vector<vector<int>>&dp)
    {
        //base cases
        if(tar<0)return 0;
        if(dice==0 && tar!=0)return 0;
        if(dice!=0 && tar==0) return 0;
        if(dice==0 && tar==0) return 1;

        if(dp[dice][tar]!=-1) return dp[dice][tar];

        int sum = 0;
        for(int i = 1;i<=face;i++)
        {
            int x = (helper(dice-1,face,tar-i,dp))%m;
            sum = (sum%m + x %m)%m;
        }
        return dp[dice][tar] = sum;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return helper(n,k,target,dp);
    }
};

------------------------------tabulation---------------------------------*/

class Solution {
public:
    int numRollsToTarget(int n, int k, int t) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<vector<int>>dp(n+1,vector<int>(t+1,0));
        dp[0][0] = 1;

        //dp[i][j] = is holding total number of ways jb hmara i dice bacha ho and we are left with j target
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=t;j++)
            {
                int sum = 0;
                for(int f = 1;f<=k;f++)
                {
                    if(f<=j) //out of bound se rokne k lie
                    sum = ((sum % m) + (dp[i-1][j-f]))%m;
                }
                dp[i][j] = sum;
            }
        }
        return dp[n][t];
    }
};


