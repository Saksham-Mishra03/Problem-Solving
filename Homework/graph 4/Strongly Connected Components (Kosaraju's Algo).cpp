void dfslast(int sv, vector<int>&visited, vector<int>rev[])
	{
	    visited[sv]=1;
	    for(auto i: rev[sv])
	    {
	        if(!visited[i])
	        dfslast(i, visited,rev);
	    }
	}
	
	void dfs(int sv, vector<int>&visited, stack<int>&stk,vector<vector<int>>& graph)
	{
	    visited[sv]=1;
	    for(auto i: graph[sv])
	    {
	        if(!visited[i])
	        dfs(i, visited, stk,graph);
	    }
	    stk.push(sv);
	}
    int kosaraju(int v, vector<vector<int>>& graph)
    {
        
        //apply kosaraju algo
        stack<int>stk;
        vector<int>visited(v,0);
        // apply dfs for kosa
        for(int i=0;i<v;i++)
        {
            if(!visited[i])
            dfs(i, visited, stk,graph);
        }
        
 
        
        //reverse the edges of graph
        vector<int>rev[v];
        
        for(int i = 0;i<v;i++)
        {
            visited[i] = 0;
            for(auto j: graph[i])
                rev[j].push_back(i);
            
        }
        
        //apply dfs and cnt no of  components
        int cnt = 0;
        while(!stk.empty())
        {
            int f = stk.top();
            stk.pop();
            
            if(!visited[f])
            {
                cnt++;
                dfslast(f, visited, rev);
            }
        }
        return cnt;
        
    }
