class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        int r = heights.size();
        int c = heights[0].size();

        vector<vector<int>>dis(r,vector<int>(c,INT_MAX));
        dis[0][0] = 0;
        pq.push({0,{0,0}}); //absdiff, row,col

        while(!pq.empty())
        {
            auto t = pq.top();
            int dif = t.first;
            int row = t.second.first;
            int col = t.second.second;
            pq.pop();

            //jo pq se bahar aya aagr bahi last index h to return kr skte h 
            if(row==r-1 && col==c-1) 
            return dif;

            int dx[] = {0,0,1,-1};
            int dy[] = {1,-1,0,0};

            //traverse in 4 directions
            for(int i = 0;i<4;i++)
            {
                int adrow = row+dx[i];
                int adcol = col+dy[i];

                if(adrow<0 || adcol<0 || adrow>=r|| adcol >=c )continue;

                int ndif = max(abs(heights[row][col]-heights[adrow][adcol]),dif);
                if(ndif < dis[adrow][adcol])
                {
                    dis[adrow][adcol] = ndif;
                    pq.push({ndif,{adrow,adcol}});
                }

            }
        }
        return 0;
    }
};
