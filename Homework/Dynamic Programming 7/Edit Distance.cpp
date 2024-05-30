/*--------------------------------recursion soln--------------------------------------------

class Solution {
public:
    int helper(string s1, string s2, int i, int j)
    {
        if(i==0 && j==0)return 0;
        if(i==0)return j;
        if(j==0)return i;
        if(s1[i-1]==s2[j-1])
        return helper(s1,s2,i-1,j-1);

        else
        {
            int a = helper(s1,s2,i,j-1)+1;
            int b = helper(s1,s2,i-1,j)+1;
            int c = helper(s1,s2,i-1,j-1)+1;
            return min(a,min(b,c));


        } 
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        return helper(word1,word2, n1, n2);
    }
};

----------------------------------------memo soln--------------------------------
class Solution {
public: 
    int helper(string s1, string s2, int i, int j,vector<vector<int>> &dp)
    {
        if(i==0 && j==0)return 0;
        if(i==0)return j;
        if(j==0)return i;

        if(dp[i][j] != -1)return dp[i][j];

        if(s1[i-1]==s2[j-1])
        return dp[i][j]=helper(s1,s2,i-1,j-1,dp);

        else
        {
            int a = helper(s1,s2,i,j-1,dp)+1;
            int b = helper(s1,s2,i-1,j,dp)+1;
            int c = helper(s1,s2,i-1,j-1,dp)+1;
            return dp[i][j]= min(a,min(b,c));
        } 
    }

    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        return helper(word1,word2, n1, n2,dp);
    }
};

--------------------------------------tabulation soln------------------------------------
class Solution {
public: 
 
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>>dp(m+1,vector<int>(n+1));
        dp[0][0] = 0;
        //filling 1st row
        for(int i = 1;i<=n;i++)
        dp[0][i] = i;

        //filling 1st column
        for(int i = 1;i<=m;i++)
        dp[i][0] = i;

        //filling entire matrix
        for(int i= 1;i<=m;i++)
        {
            for(int j = 1;j<=n;j++)
            {
                if(word1[m-i]==word2[n-j])
                dp[i][j] = dp[i-1][j-1];
                else
                {
                    dp[i][j] = 1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                }
            }
        }
        return dp[m][n];
    }
};

------------------------------obtimised tabulation ------------------------------------------*/

class Solution {
public: 
 
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();


        vector<int> temp1(n+1, 0);
        vector<int> temp2(n+1, 0);

        for(int j=0; j<=n; j++)
        temp1[j] = j; //1st row 

        for(int i= 1;i<=m;i++)
        {
            temp2[0]=i;
            for(int j = 1;j<=n;j++)
            {
                if(word1[i-1]==word2[j-1])
                temp2[j] = temp1[j-1];
                else
                {
                    int add = 1 + temp2[j-1];//usi row ka previos
                    int del = 1 + temp1[j]; //pichli row ka just upar
                    int rep = 1 + temp1[j-1]; // diagonal upar jo temp 1 pe hoga
                    temp2[j] = min(add,min(del,rep));   
                }
            }
            temp1 = temp2; //next time k lie row update krdo
        }
        return temp1[n];
    }
};
