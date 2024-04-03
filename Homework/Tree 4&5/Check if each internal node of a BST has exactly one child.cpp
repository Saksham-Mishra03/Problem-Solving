#include<bits/stdc++.h>
using namespace std;
bool check(vector<int>&pre, int n)
{
	for(int i = 0;i<n-1;i++)
	{
		int next = pre[i+1];
		int last = pre[n-1];
		
		if((pre[i]>next && pre[i]>last) || pre[i]<next && pre[i]<last)
		continue;
		else
		return false;
	}
	return true;
}
int main()
{
	int n;
	cin>>n;
	vector<int>pre(n);
	for(int i = 0;i<n;i++)
	cin>>pre[i];
	
	if(check(pre,n))
	cout<<"yes";
	else
	cout<<"no";
}

//TC: O(N)
//SPace : O(1)
