bool isvalid(int x,  int y, int A, int B)
{
    return (x<=A && x>=1 && y<=B && y>=1);
}

int Solution::knight(int A, int B, int C, int D, int E, int F) {
    
    if(C==E && F==D)
        return 0;
    
    vector<vector<int>>visited(A+1,vector<int>(B+1,0));
   vector<int>dx = {1,1,-1,-1,2,2,-2,-2};
   vector<int>dy = {2,-2,-2,2,-1,1,-1,1};
   queue<pair<int,int>>q;
   q.push({C,D});
   visited[C][D] = 1;
   int ans = 0;
    
    //now start bfs
    while(!q.empty())
    {
        int size = q.size();
        while(size--)
        {
            int x = q.front().first;
            int y= q.front().second;
            q.pop();
            
            for(int i = 0;i<8;i++)
            {
                int nx = x + dx[i];
                int ny = y+ dy[i]; 
                
                if(isvalid(nx,ny,A,B) && !visited[nx][ny])
                {
                    if(nx==E && ny == F)return ans+1;
                q.push({nx,ny});
                visited[nx][ny]  =1;
                }
                
            }
        }
        ans++;
    }
   return -1;
    
    
}
