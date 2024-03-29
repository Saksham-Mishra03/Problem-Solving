#include<bits/stdc++.h>
using namespace std;
int count(int a, int b, int c, int mid)
{
    //lcm stl fxn
	return ((mid / a) + (mid / b) + (mid / c) - (mid / lcm(a, b))- (mid / lcm(b, c)) - (mid / lcm(a, c))+ (mid / lcm(a, lcm(b, c)))); 
}

int Ndiv(int a, int b, int c, int n)
{
	int l = 0; 
	int h = INT_MAX;
	
	while(l<=h)
	{
		int mid  = (l+h)/2;
		//count fxn btaega kitne elements mid se divisible h agr bo n k barabar h to hmara ans mil gya else kuch kuch kro
		if(count(a,b,c,mid)==n) 
		{
			return mid;
		}
		else if(count(a,b,c,mid)<n)
		{
			l = mid+1;
		}
		else
		h = mid-1;
	} 
	return -1;
}

int main()
{
	int a,b,c,n;
	cin>>a>>b>>c>>n;
	cout<<Ndiv(a,b,c,n);
}
