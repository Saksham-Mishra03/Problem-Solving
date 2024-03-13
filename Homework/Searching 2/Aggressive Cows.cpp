   bool canplaced(vector<int>&stalls, int dis, int n, int tcows)
    {
        int cow = 1;
        int sum = 0;
        int lastplaced = stalls[0];
        for(int i = 0;i<n;i++)
        {
            if(stalls[i]-lastplaced >= dis)
            {
                cow++;
                lastplaced = stalls[i];
            }
        }
        return cow>=tcows;
    }

/*
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        for(int i:stalls)
        {
         //   mini = min(mini,i);
            maxi = max(maxi,i);
        }
        mini=1;
        
        //now checking for distance at which cows can be placed
        for(int i = mini;i<=maxi;i++)
        {
            if(canplaced(stalls, i, n, k))
            return i;
        }
        return -1;
    }
    
    */
    
        int solve(int n, int k, vector<int> &stalls) {
            
        sort(stalls.begin(),stalls.end());
        int ans = 1;
    /*
        // Write your code here
        int mini = 1;
        int maxi = INT_MIN;
        
        for(int i:stalls)
        {
         //   mini = min(mini,i);
            maxi = max(maxi,i);
        }
        
        */
        int l = 1;
        int h = stalls[n-1]-stalls[0]+1;
        
        while(l<=h)
        {
            int mid  = (l+h)/2;
            if(canplaced(stalls,mid,n,k))
            {
                ans = mid;
                l = mid+1;
            }
            else
            {
                h = mid-1;
            }
            
        }
        return ans;
        
    }
    
