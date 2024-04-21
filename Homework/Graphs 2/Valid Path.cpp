bool checkcircle(int x, int y, int r, vector<int> &E, vector<int> &F){

    for(int i=0;i<E.size();i++){
        int x1=E[i],y1=F[i];
        if( (x-x1)*(x-x1) + (y-y1)*(y-y1) <= r*r ){
            return 0;
        }
    }
    return 1;
}

bool dfs(int i, int j,int A, int B, int C, int D, vector<int> &E, vector<int> &F, vector<vector<int>> &visited)
{
    
    // base case agr destination tk pahuch gya
    vector<int>dx = {1,1,0,-1,0,-1,-1,1};
    vector<int>dy = {1,0,1,0,-1,-1,1,-1};
    
    if(i==A && j==B && checkcircle(i,j,D,E,F))
    return true;
    
    if(i>=0 && j>=0  && i<=A && j<=B && checkcircle(i,j,D,E,F) && visited[i][j]==0)
    {
        visited[i][j] = 1;
        for(int k = 0;k<8;k++)
        {
            int ni = i+dx[k];
            int nj = j+ dy[k];
            if(dfs(ni,nj,A,B,C,D,E,F,visited)) return true;
        }
    }
    return false;
}

string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    
    vector<vector<int>>visited(A+1,vector<int>(B+1,0));
    if(dfs(0,0,A,B,C,D,E,F,visited))
    return "YES";
    return"NO";
}
