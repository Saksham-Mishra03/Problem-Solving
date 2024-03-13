#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int ar[n];
	for(int i= 0;i<n;i++)
	cin>>ar[i];
	
	int s;
	cin>>s;
	
	sort(ar,ar+n);
	
	int cnt = 0;
	int sum=0;
	for(int i= n-1;i>=0;i--)
	{
		
		if(sum+ar[i]<s)
		{
		sum+= ar[i];
		cnt++;
		}
		else
		{
			if(sum+ar[i]==s)
			{
				cout<<cnt+1;
				break;
			}
			else
			{
				cout<<cnt;
				break;
			}
		}
	}
}
