class Solution {
public:
    int maxScore(vector<int>&c, int k) {
        int i =0,j =c.size()-1;
        int sum = 0;
        while(i<k){
            sum += c[i];
            i++;
        }
        i--; //jb loop break hoga toh i bad chuka hoga use piche krna by 1
        int maxi = sum;
        while(i>=0){
            sum = sum -c[i] +c[j];
            i--;
            j--;
            maxi = max(maxi,sum);
        }
        return maxi;
    }
};
