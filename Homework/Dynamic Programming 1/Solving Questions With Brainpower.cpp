
/**********************recursion soln(tle)**********************************/

class Solution {
public:
    long long helper(vector<vector<int>>& questions, int i, int n)
    {
        if(i>=n)return 0;
        long long inc = questions[i][0] + helper(questions,i+questions[i][1]+1,n);
        long long exc = helper(questions,i+1,n);
        return max(inc, exc);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        return helper(questions,0,n);
    }
};

/*********************************recur+memo*************************************************/

class Solution {
public:
    long long helper(vector<vector<int>>& questions, int i, int n,vector<long long> &dp)
    {
        if(i>=n)return 0;
        if(dp[i]!=-1)
        return dp[i];

        long long inc = questions[i][0] + helper(questions,i+questions[i][1]+1,n,dp);
        long long exc = helper(questions,i+1,n,dp);

        dp[i] =  max(inc, exc);
        return dp[i];
    }
    long long mostPoints(vector<vector<int>>& questions) {
        long long n = questions.size();
        vector<long long>dp(n+1,-1);
        return helper(questions,0,n,dp);
    }
};

/*****************************tabulation soln********************/

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        long long n = questions.size();
        vector<long long>dp(1e6,0);
        dp[0] = questions[0][0];

        for(int i = n-1;i>=0;i--)
        dp[i] = max(dp[i+1], (questions[i][0]+ dp[i+questions[i][1]+1]));

        return dp[0];
    }
};
