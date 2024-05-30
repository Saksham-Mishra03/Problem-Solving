class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.size();
        int n2 = str2.size();
        vector<vector<int>>dp(n1+1, vector<int>(n2+1,0));
        
        //lcs logic
        //if(any 1 text length is 0, so no of subsequence will be 0 so dp[i][j] = 0 for 0th row and col)

        for(int i = 0;i<=n1;i++) dp[i][0] = 0;
        for(int i = 0;i<=n2;i++) dp[0][i] = 0;

        //fill entrire matrix
        for(int i =1;i<=n1; i++){
            for(int j = 1;j<=n2;j++){
                if(str1[i-1]==str2[j-1]) 
                dp[i][j] = 1+dp[i-1][j-1];
                else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        // dp me bapas jao
        string ans = "";
        int i = n1,j=n2;
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                ans += str1[i-1];
                i--;
                j--;
            }

            else if(dp[i-1][j]>dp[i][j-1]){
                ans+=str1[i-1];
                i--;
            }
            else
            {
                ans+=str2[j-1];
                j--;
            }
        }
        //ek end tk pahuch jae and dusra rah jae use handle krne k lie
        while(i>0)
        {
            ans+=str1[i-1];
            i--;
        }
        while(j>0)
        {
            ans+=str2[j-1];
            j--;
        }
       reverse(ans.begin(),ans.end());
       return ans;
    }
};
