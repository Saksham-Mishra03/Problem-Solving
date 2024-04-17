class Solution {
public:
    bool checkdfs(vector<vector<int>> &graph,vector<int> &visited, int s, int d)
    {
        if(s==d)
        return true;
        if(visited[s])
        return false;

        visited[s] = 1;
        for(int i=0; i<graph[s].size(); i++){
            if(checkdfs(graph, visited, graph[s][i], d))
                return true;
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

         vector<vector<int>> graph(n);
         vector<int> visited(n, 0);
        for(int i=0; i<edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        // for(int i = 0;i<n;i++)
        // {
        //     if(checkdfs(graph,visited, source, destination))
        //     return true;
        // }
        // return false;
        return checkdfs(graph,visited, source, destination);
    }
};
