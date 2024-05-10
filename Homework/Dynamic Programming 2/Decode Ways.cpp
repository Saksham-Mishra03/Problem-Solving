/*--------------------------------------recursion soln--------------------------

class Solution {
public:
    int solve(int i, string s, int n,vector<int>&dp)
    {
        if(i>=n)return 1; //reached till end 1 way found
        if(s[i]=='0') return 0;

        if(dp[i]!=-1)return dp[i];

        int ans = solve(i+1,s,n,dp);

        int ans2;
        if(i+1<n) // i out of bound na chla jae
        {
            if(s[i]=='1' || (s[i]=='2' && s[i+1]<='6'))
            ans += solve(i+2,s,n,dp);
        }
        return dp[i] = ans;

    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n+1,-1);

        return solve(0,s,n,dp);
        
    }
};

--------------------------recur+memo -----------------------------------------
class Solution {
public:
    int solve(int i, string s, int n,vector<int>&dp)
    {
        if(i>=n)return 1; //reached till end 1 way found
        if(s[i]=='0') return 0;

        if(dp[i]!=-1)return dp[i];

        int ans = solve(i+1,s,n,dp);

        int ans2;
        if(i+1<n) // i out of bound na chla jae
        {
            if(s[i]=='1' || (s[i]=='2' && s[i+1]<='6'))
            ans += solve(i+2,s,n,dp);
        }
        return dp[i] = ans;

    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n+1,-1);
        return solve(0,s,n,dp);     
    }
};
------------------------tabulation-----------------------------------------------------*/

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        vector<int>dp(n+1);
        dp[n] = 1; //empty string the pahuche means we got 1 result

        for(int i = n-1;i>=0;i--)
        {
            if(s[i]=='0')//hm kabhi use apni string me add ni kr paege 
            dp[i] = 0;
            else{
                dp[i]  = dp[i+1];
                if(i+1<n)
                {
                    if(s[i]=='1'|| (s[i]=='2' && s[i+1]<='6'))
                    dp[i] += dp[i+2];
                }
            }

        }

        return dp[0];
    }
};
