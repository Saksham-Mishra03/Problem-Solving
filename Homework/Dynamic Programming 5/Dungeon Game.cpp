class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();

        vector<vector<int>>dp(r,vector<int>(c,INT_MAX));

        //filling the last cell a special case
        if(mat[r-1][c-1]>0) 
        dp[r-1][c-1] = 1;
        if(mat[r-1][c-1]<=0) 
        dp[r-1][c-1] = abs(mat[r-1][c-1])+1;


        //filling the last column
         for(int i = r-2; i >= 0; i--) {
            dp[i][c-1] = max(1, dp[i+1][c-1] - mat[i][c-1]); //for this refer note below
         }

         //filling the last row
         for(int i = c-2; i >= 0; i--) {
            dp[r-1][i] = max(1, dp[r-1][i+1] - mat[r-1][i]); //for this refer note below
         }



        //filling the rest of the dp array
        for(int i = r-2;i>=0;i--)
        {
            for(int j = c-2;j>=0;j--)
            {
                //if(i==r-1 && j==c-1)continue;
                /*
                int adjmin;
                if(j==0 || j==c-1)
                adjmin = dp[i+1][j];
                else if(i==0 || j==r-1)
                adjmin = dp[i][j+1];
                else
                */
               int adjmin = min(dp[i+1][j],dp[i][j+1]); //dono adjacent jha se aa skta h uska minimum value

                if(mat[i][j]<=0)//agr mat me -ve or 0 h dono direction jha se aya uska min lo mat ki abs value add kro
                {
                    dp[i][j] = abs(mat[i][j]) + adjmin;
                }
                else //agr mat ki value +ve to adj dp se compare krege ki choti ya badi and then decide krege for both 2 casses
                {
                    if(mat[i][j]>=adjmin)//agr matrix me hme health jada mil dp pe km chahye adjacent ko toh mat pe jinda rhne k lie 1 bhi chlega  
                        dp[i][j] = 1;
                    else //agr dp me jitni chaiye usse km h mat k pas to required k lie dp adj bali se subtract krdege
                    {
                        dp[i][j] = adjmin-mat[i][j];
                    }

                    //**note: upar dono condition ko simplify by://   dp[i][j] = max(1, adjmin-mat[i][j])   //annkan bhiay ka trick
                }
            }
        }
        return dp[0][0];
        
    }
};
