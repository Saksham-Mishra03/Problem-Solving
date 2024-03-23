int countlessthanmid(int mat[MAX][MAX], int n , int mid)
{
    int cnt = 0;
    for(int i = 0;i<n;i++)
    {
        cnt += upper_bound(mat[i],mat[i]+n, mid)-mat[i];
    }
    return cnt;
}

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //Your code here
  int l = mat[0][0];
  int r = mat[n-1][n-1];
  
  while(l<=r)
  {
      int mid = (l+r)/2;
      
      int cnt = countlessthanmid(mat, n ,mid);
      
      if(cnt<k)
      l = mid+1;
      else
      r = mid-1;
  }
  return l;
  
}
