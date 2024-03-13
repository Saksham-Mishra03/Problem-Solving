class Solution {
public:

    bool possible(vector<int>&b, int x, int m, int k)
    {
        int nom = 0; 
        int cnt = 0;
        for(int i = 0;i<b.size();i++)
        {
            if(b[i]<=x)
            {
                cnt++;
            }
            else
            {
                nom += cnt/k;
                cnt = 0;
            }
        }
            nom += cnt/k;
        return nom>=m;
    }
 /*   
    int minDays(vector<int>& b, int m, int k) {
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int i :b)
        {
            mini = min(mini,i);
            maxi = max(maxi,i);
        }
        for(int i = mini;i<=maxi;i++)
        {
            if(possible(b,i,m,k))
            return i;
        }
        return -1;
    }
*/
    //binary search
        int minDays(vector<int>& b, int m, int k) {
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int i :b)
        {
            mini = min(mini,i);
            maxi = max(maxi,i);
        }
        int low = mini;
        int high = maxi;

        int ans = -1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(possible(b,mid,m,k))
            {
                ans = mid;
                high = mid-1;
            }
            else
            low = mid+1;
        }
        return ans;
    }
};
