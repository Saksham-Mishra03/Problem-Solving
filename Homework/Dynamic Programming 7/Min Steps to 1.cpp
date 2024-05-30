/*--------------------------------------recursion------------------------------------------------------
  int countMinStepsToOne(int n)
{
	//Write your code here
	if(n==1)
	return 0;
	int x=countMinStepsToOne(n-1);

	int y=INT_MAX;
	if(n%2==0)
	 y=countMinStepsToOne(n/2);

	 int z=INT_MAX;
	 if(n%3==0)
	z=countMinStepsToOne(n/3);
	
	return min(x,min(y,z))+1;
}

------------------------------------------------memoisation-------------------------------------------------
int helper(int n,vector<int>&ans )
{
	if(n<=1)
	return 0;

	if(ans[n]!=-1)
	return ans[n];

	int x=helper(n-1, ans);
	int y = INT_MAX,z= INT_MAX;

	if(n%2==0)
	y = helper(n/2, ans);

	if(n%3==0)
	z=helper(n/3, ans);

	int out = min(x,min(y,z))+1;

	ans[n]=out;
	return out;


}
int countStepsToOne(int n)
{
	//Write your code here
	vector<int>ans(n+1,-1);
	return helper(n,ans);
}

--------------------------------------------------------------------tabulation-----------------------------------*/

int countStepsToOne(int n)
{
    int *dp = new int[n + 1];
    
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for (int i = 4; i <= n; i++){
        int a = n, b = n;
        if (i % 2 == 0){
            a = dp[i / 2];
        }
        if (i % 3 == 0){
            b = dp[i / 3];
        }
        dp[i] = min(dp[i - 1], min(a, b)) + 1;
    }
    return dp[n];
}


