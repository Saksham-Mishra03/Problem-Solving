#include<bits/stdc++.h>

bool canPartition(vector<int> &boards, int x, int n,int k)
{
    int sum = 0;
    int cnt = 1;
    for(int i = 0;i<boards.size();i++)
    {
        if(sum+boards[i]<=x)
        {
            sum+=boards[i];
        }
        else
        {
            cnt++;
            sum = boards[i];
        }
    }
    return cnt>k;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int n = boards.size();
   // int mini = INT_MAX;
    int maxi = INT_MIN;
    int sum = 0;
    for(int i:boards)
    {
        //mini = min(mini,i);
        maxi = max(maxi,i);
        sum +=i;
    }
    int l = maxi;
    int h = sum;
    int ans = -1;

    while(l<=h)
    {
        int mid = (l+h)/2;
        if(canPartition(boards,mid,n,k))
        {
            //ans = mid;
            l = mid+1;
        }
        else
        {
            h = mid-1;
        }
    }
    return l;
}
