class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
      int m = grid.size();
      int n = grid[0].size();
        int total = 0;
        int cnt = 0;
      queue<pair<int,int>>q;
      for(int i = 0;i<m;i++)
      {
        for(int j = 0;j<n;j++)
        {
            if(grid[i][j]==2)
            q.push({i,j});
            if(grid[i][j]!=0)
            total++;
        }
      }
      vector<int>dx = {1,-1,0,0};
      vector<int>dy = {0,0,-1,1};
      int time = 0;
      //apply bfs and move on to cell where not rotten
      while(!q.empty())
      {
        int k = q.size();
        cnt+=k;
        while(k--)
        {
            auto f= q.front();
            q.pop();
            int x = f.first;
            int y = f.second;
            for(int i = 0;i<4;i++)
            {
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx>=0 && nx<m && ny >=0 && ny<n && grid[nx][ny]==1)
                {
                    grid[nx][ny]=2;
                    q.push({nx,ny});
                }
            }
        }
            if(!q.empty())
            time++;
        }
        if(total == cnt)
        return time;
        return -1;
      

    }
};
