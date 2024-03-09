	int NthRoot(int n, int m)
	{
	    // Code here.
	    int l = 1;
	    int r = m;
	    while(l<=r)
	    {
	        int mid = (l+r)/2;
	        if(pow(mid,n)==m) 
	        return mid;
	        else if(pow(mid,n)<m)
	        {
	            //ans = mid;
	            l  = mid+1;
	        }
	        else
	        {
	            r = mid-1;
	       }
	    }
	    return -1;
	}  
