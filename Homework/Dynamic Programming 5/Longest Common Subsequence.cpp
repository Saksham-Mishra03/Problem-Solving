/*-------------------------recursive sol-----------------------------
class Solution {
public:
    int helper(int i, string t1, int j, string t2, int n1, int n2){
        if(i>=n1 || j>=n2)return 0;


        //if 1st char is matching
        if(t1[i]==t2[j])
        return 1+ helper(i+1,t1,j+1, t2,n1,n2);
        else
        return max(helper(i+1,t1,j, t2,n1,n2),helper(i,t1,j+1, t2,n1,n2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        return helper(0,text1, 0, text2, n1,n2 );
    }
};
---------------------------recur+memo -----------------------------------
class Solution {
public:
    int helper(int i, string &t1, int j, string &t2, int n1, int n2,vector<vector<int>>&dp){
        if(i>=n1 || j>=n2)return 0;
        if(dp[i][j]!=-1)return dp[i][j];

        //if 1st char is matching
        if(t1[i]==t2[j])
        dp[i][j] =  1+ helper(i+1,t1,j+1, t2,n1,n2,dp);
        else
        dp[i][j] = max(helper(i+1,t1,j, t2,n1,n2,dp),helper(i,t1,j+1, t2,n1,n2,dp));
        return dp[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>>dp(n1+1, vector<int>(n2+1,-1));
        return helper(0,text1, 0, text2, n1,n2 ,dp);
    }
};

-------------------------------tabulation---------------------------------*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>>dp(n1+1, vector<int>(n2+1,0));
        
        //if(any 1 text length is 0, so no of subsequence will be 0 so dp[i][j] = 0 for 0th row and col)

        for(int i = 0;i<=n1;i++) dp[i][0] = 0;
        for(int i = 0;i<=n2;i++) dp[0][i] = 0;

        //fill entrire matrix
        for(int i =1;i<=n1; i++){
            for(int j = 1;j<=n2;j++){
                if(text1[i-1]==text2[j-1]) 
                dp[i][j] = 1+dp[i-1][j-1];
                else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n1][n2];
    }
};
