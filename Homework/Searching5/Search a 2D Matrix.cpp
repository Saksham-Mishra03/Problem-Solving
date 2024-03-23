/***********************
//linear  traversal brute force solution

class Solution {
public:

    int searchrow(vector<vector<int>>& matrix, int target)
    {
        int c = matrix[0].size();
        int ans=-1;
        for(int i = 0;i<matrix.size();i++)
        {
            if(target>=matrix[i][0] && target <= matrix[i][c-1])
            {
                ans = i;
                break;
            }
        }
        return ans;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {


            int row = searchrow(matrix,target);
            if(row==-1)
            return false;
            int c = matrix[0].size();
            bool check = false;

            for(int i = 0;i<c;i++)
            {
                if(target==matrix[row][i])
                {
                    check = true;
                    break;
                }
            }
        return check;
    }
};

***********************************/


//binary search solution

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int l = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int r = (n*m)-1;

        while(l<=r)
        {
            int mid = (l+r)/2;
            int cntrowofmid = mid/m;
            int cntcolofmid = mid%m;

            if(matrix[cntrowofmid][cntcolofmid]==target)
            return true;
            else if(matrix[cntrowofmid][cntcolofmid]<target)
            l = mid+1;
            else
            r = mid-1;
        }
        return false;
    }
};
