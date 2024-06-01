/* ------------------------------recur + memo--------------------------

class Solution {
public:
    bool recur(string &s, string &p, int i, int j,vector<vector<int>>&dp)
    {
        if(i<0 && j<0)return true;//agr dono string ktm to true
        if(i>=0 && j<0)return false; // s bachi pr p khatam to false
        if(i<0 && j>=0) //agr p bacha h to true tabhi hoga jb bo pura star ho
        {
            for(int k =0;k<=j;k++)
            {
                if(p[k]!='*')
                {
                    return false;
                }
            }
            return true;
        }

        if(dp[i][j]!=-1)return dp[i][j];

        if(s[i]==p[j] || p[j]=='?')
        {
            return dp[i][j] = recur(s,p,i-1,j-1,dp);
        }
        else if(p[j]=='*')
        {
            return dp[i][j] = recur(s,p,i-1,j,dp) || recur(s,p,i,j-1,dp);
        }
        else
        {
            return false;
        }
    }
    bool isMatch(string s, string p) {
        int n =s.size();
        int m = p.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return recur(s,p,n-1,m-1,dp);
    }
};

------------------------------------------------------------------*/

class Solution {
public:
    bool isMatch(string s, string p) {
        int n =s.size();
        int m = p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        dp[0][0] = true;

        // dp [i][j] represent if the string match till i and j 
        for(int j=1;j<=p.length();j++)
        {
        bool flag= true;
            for(int k =1;k<=j;k++)
            {
                if(p[k-1]!='*')
                {
                    flag=false;
                    break;
                }
            }
            dp[0][j]=flag;
        }

            for(int i =1;i<=n;i++)
            {
                for(int j =1;j<=m;j++)
                {
                    if(p[j-1]=='?' || p[j-1]==s[i-1])
                    {
                        dp[i][j]=dp[i-1][j-1];
                    }
                    else if(p[j-1]=='*')
                    {
                    dp[i][j]=dp[i-1][j] || dp[i][j-1];
                    }
                    else
                    {
                        dp[i][j]=false;
                    }
                }
            }
    return dp[n][m];

        
    }
};
