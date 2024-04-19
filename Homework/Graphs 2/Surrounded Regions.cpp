class Solution {
public:
    vector<int>dx = {1,-1,0,0};
    vector<int>dy = {0,0,-1,1};
    void DFS(vector<vector<char>>& board,int i, int j,int m,int n )
    {
        if(i<0 or j<0 or i>=m or j>=n or board[i][j] != 'O') return;
        board[i][j] = '$';
        DFS(board, i-1, j, m, n);
        DFS(board, i+1, j, m, n);
        DFS(board, i, j-1, m, n);
        DFS(board, i, j+1, m, n);
        
    }


    void solve(vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();

        for(int i = 0;i<n;i++) //row = 0  k lie
        {
            if(board[0][i]=='O')
            DFS(board,0,i,m,n);
        }
        for(int i = 0;i<n;i++) //row = m-1  k lie
        {
            if(board[m-1][i]=='O')
            DFS(board,m-1, i,m,n);
        }
        for(int i = 0;i<m;i++) //col = 0  k lie
        {
            if(board[i][0]=='O')
            DFS(board,i,0,m,n);
        }
        for(int i = 0;i<m;i++) //col = n-1  k lie
        {
            if(board[i][n-1]=='O')
            DFS(board,i, n-1,m,n);
        }
        //1st row ya 1st column chod k baki purri matrix ko x krdo
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(board[i][j]!='$')
                board[i][j] = 'X';
            }
        }
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(board[i][j]=='$')
                board[i][j] = 'O';
            }
        }

        
    }
};
