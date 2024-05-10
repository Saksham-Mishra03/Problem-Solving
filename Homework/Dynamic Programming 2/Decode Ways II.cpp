/*----------------------------------recursion sol-----------------------------
class Solution {
public:
    int helper(string s, int idx, int n)
    {
        if(idx==n)return 1;
        if(s[idx]=='0')return 0;

        int res = 0;

        int mult; //agr * mila to bo 9 combinations bnaege so 9 multiply krega else 1 multiply krega
        if(s[idx]=='*')mult = 9;
        else mult = 1;

        res += mult*helper(s,idx+1,n); //for taking only 1st char i.e. idx char
         if(idx<n-1)
         {
            int comb = 0;
            char cur = s[idx];
            char next = s[idx+1];

            if(cur=='*')
            {
                if(next=='*')
                {
                    comb = 15; //1st star make 9 combination 2nd can make only 6 i.e 1 to 6
                }
                else
                {
                    if(next<='6') comb = 2;
                    else comb  = 1;
                }
            } 

            if(cur=='1' || cur=='2')
            {
                if(next=='*')
                {
                    if(cur=='1') comb = 9;
                    if(cur=='2') comb = 6;
                }
                else
                {
                    if(stoi(s.substr(idx,2))<=26)
                    comb = 1;
                }
            }

            if(comb)
            {
                res += comb *helper(s, idx+2,n); 
            }
         }
        return res;

    }
    int numDecodings(string s) {
        int n = s.size();
        return helper(s,0,n);
        
    }
};

-------------------------------recur+memo-----------------------------------*/
typedef long long ll;
class Solution {
public:
    ll mod = 1000000007;
    int helper(string &s, int idx, int n,vector<ll>&dp)
    {
        if(idx==n)return 1;
        if(s[idx]=='0')return 0;
        if(dp[idx]!=-1) return dp[idx];
        ll res = 0;

        ll mult; //agr * mila to bo 9 combinations bnaege so 9 multiply krega else 1 multiply krega
        if(s[idx]=='*')mult = 9;
        else mult = 1;

        res += mult*helper(s,idx+1,n,dp); //for taking only 1st char i.e. idx char
         if(idx<n-1)
         {
            ll comb = 0;
            char cur = s[idx];
            char next = s[idx+1];

            if(cur=='*')
            {
                if(next=='*')
                {
                    comb = 15; //1st star make 9 combination 2nd can make only 6 i.e 1 to 6
                }
                else
                {
                    if(next<='6') comb = 2;
                    else comb  = 1;
                }
            } 

            if(cur=='1' || cur=='2')
            {
                if(next=='*')
                {
                    if(cur=='1') comb = 9;
                    if(cur=='2') comb = 6;
                }
                else
                {
                    if(stoi(s.substr(idx,2))<=26)
                    comb = 1;
                }
            }

            if(comb)
            {
                res += comb *helper(s, idx+2,n,dp); 
            }
         }
        return dp[idx] = res%mod;

    }
    int numDecodings(string s) {
        int n = s.size();
        vector<ll>dp(n+1,-1);
        return helper(s,0,n,dp);
        
    }
};
