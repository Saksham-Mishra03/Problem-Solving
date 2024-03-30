class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	    int l = 0,r = n-1;
	    int ans = 0;
	    while(l<=r)
	    {
	        int mid = (l+r)/2;
	        if(arr[mid]>=arr[0])
	        {
	            
	            l = mid+1;
	        }
	        else
	        {
	            ans = mid;
	            r = mid-1;
	        }
	    }
	    
	    return ans;
	}

};
