
#include<bits/stdc++.h>
int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
    if(n>m)
    return kthElement(arr2, arr1, m, n, k);

    int l  = max(0,k-m);
        int r  = min(n,k);

        while(l<=r)
        {
            int mid1 = (l+r)/2;
            int mid2 = k-mid1;

            int l1 = (mid1==0)?INT_MIN : arr1[mid1 -1]; //intmin , intmax sirf islie dale h jisse ek array khatam hone pe boundry bani rahe 
            int l2 = (mid2==0)? INT_MIN : arr2[mid2-1];
            int r1 = (mid1==n)?INT_MAX : arr1[mid1];
            int r2 = (mid2==m)?INT_MAX : arr2[mid2];

            if(l1<= r2 && l2<=r1)
            {
                return max(l1,l2);
            }
            else if(l1>r2)
            {
                r = mid1-1;
            }
            else
            l = mid1+1;
        }
        return 0;
}
