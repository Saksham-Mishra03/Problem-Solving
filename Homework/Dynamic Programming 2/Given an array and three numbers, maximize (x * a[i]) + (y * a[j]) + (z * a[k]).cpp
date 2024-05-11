
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i = 0;i<n;i++)
    cin>>a[i];
    
    int x,y,z;
    cin>>x>>y>>z;
    
    //finding leftmost maximum value
    int L[n]; 
    L[0] = x * a[0]; 
    for (int i = 1; i < n; i++)  
        L[i] = max(L[i - 1], x * a[i]); 
    
    //finding rightmost maximum value
    int R[n]; 
    R[n-1] = z * a[n-1]; 
    for (int i = n - 2; i >= 0; i--) 
        R[i] = max(R[i + 1], z * a[i]); 
        
    //now maximize the result
    int res = INT_MIN;  
    for (int i = 0; i < n; i++)  
          res = max(res, L[i] + y * a[i] + R[i]);  
  
    cout<<res<<endl; 
}
