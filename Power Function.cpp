#include<iostream>
using namespace std;

int powerf(int x,int n)
{
	if(n==1) return x;
	if(n%2!=0) return x*powerf(x,n-1);
	return powerf(x,n/2)*powerf(x,n/2);
}

int main()
{
	int x,n;
	cin>>x>>n;
	cout<<powerf(x,n);
}