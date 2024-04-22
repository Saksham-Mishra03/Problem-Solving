class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int m = grid.size();
	    int n = grid[0].size();
	    queue<pair<int,int>>q;
	    vector<vector<int>>ans(m,vector<int>(n,-1));
	    
	    for(int i = 0;i<m;i++)
	    {
	        for(int j = 0;j<n;j++)
	        {
	            if(grid[i][j]==1)
	            {
    	            q.push({i,j});
    	            ans[i][j] = 0;
	            }
	        }
	    }
	    
	    int lvl = 0;
	    vector<int>dx = {1,-1,0,0};
	    vector<int>dy = {0,0,1,-1};
	    
	    // apply bfs
	    while(!q.empty())
	    {
	        int size = q.size();
	        while(size--)
	        {
	            auto f = q.front();
	            int x = f.first;
	            int y = f.second;
	            
	            q.pop();
	            
	            //traverse the neighbours of x,y via bfs
	            for(int i = 0;i<4;i++)
	            {
	                int nx = x+dx[i];
	                int ny = y+dy[i];
	                
	                if(nx<0 || ny<0 || nx>= m || ny>=n || ans[nx][ny]!=-1) continue;
	                
	                q.push({nx, ny});
	                ans[nx][ny] = ans[x][y]+1;
	            }
	        }
	        //lvl++;
	    }
	    return ans;
	}
};
