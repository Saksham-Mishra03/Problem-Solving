//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

#define ll long long int
class Solution
{
public:
ll mod = 1000000007;
/*--------------------------recursion------------------------------------------
    int countFriendsPairings(int n) 
    { 
        // code here
        if(n==0)return 1;
        //if(n==1)return 1;
        //if(n==3) return 2;
        
        int single = countFriendsPairings(n-1);
        
        int dob = 0;
        if(n>=2)
        dob = countFriendsPairings(n-2)*(n-1);
        
        return single+dob;
        
    }
    -----------------------------recur+memo----------------------------------------
    int helper(int n,vector<ll>&dp)
    {
        if(n==0)return 1;
        //if(n==1)return 1;
        //if(n==3) return 2;
        if(dp[n]!=-1)return dp[n];
        
        ll single = helper(n-1,dp)%mod;
        
        ll dob = 0;
        if(n>=2)
        dob = ((helper(n-2,dp)%mod)*(n-1))%mod;
        
        return dp[n] = (single+dob)%mod;
        
    }
    int countFriendsPairings(int n) 
    { 
        // code here
        vector<ll>dp(n+1,-1);
        return helper(n,dp);
    }
    
    ----------------------------------tabulation-----------------------------------*/
    int countFriendsPairings(int n) 
    { 
        vector<ll>dp(n+1);
        //dp[i] = no of ways in which i people can make friend
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        
        ll ways = 0; 
        for(int i=3;i<=n;i++)
        {
            ways = ((dp[i-1])%mod)%mod;
            ways = (ways +((dp[i-2])%mod*(i-1))%mod)%mod;
            dp[i] = ways;
        }
        return dp[n];
    }
};    
 

//{ Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends
