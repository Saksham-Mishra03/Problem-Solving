//linear seach solution giving tle at atcoder. working for optimisation

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,q;
	cin>>n>>q;
	
	vector<int>a(n);
	for(int i = 0;i<n;i++)
	cin>>a[i];
	
	while(q--)
	{
		int x;
		cin>>x;
		
		int cnt = 0;
		for(int i = 0;i<n;i++)
		{
			if(a[i]>=x)
			cnt++;
		}
		cout<<cnt<<endl;
	}
}
