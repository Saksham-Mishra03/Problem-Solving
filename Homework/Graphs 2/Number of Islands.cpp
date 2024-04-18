class Solution {
public:
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    void dfs(vector<vector<char>>& grid, int x, int y,int r, int c)
    {
        if(x<0 || y<0|| x>=r || y>=c || grid[x][y]=='0')
        return;

        grid[x][y] = '0';
        for(int i  =0;i<4;i++)
        {
            int nx = dx[i]+x;
            int ny = dy[i]+y;
            dfs(grid,nx,ny, r,c);
        }
        

    }
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        //vector<vector<int>>visited;

        int cnt = 0;
        for(int i = 0;i<r;i++)
        {
            for(int j = 0;j<c;j++)
            {
                if(grid[i][j]=='1')
                {
                    cnt++;
                    dfs(grid, i,j, r,c);
                }
            }
        }
        return cnt;
    }
};
