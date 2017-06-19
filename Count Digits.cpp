#include<iostream>
using namespace std;

int occurenceDig(int n,int x)
{
	int count = 0;
	int temp = n;
	int dign;
	while(temp!=0)
	{
		dign = temp%10;
		temp = temp/10;
		if(dign == x)
			count ++;
	}
	return count;
}

int main()
{
	int n;
	cin>>n;

	int x;
	cin>>x;

	cout<< occurenceDig(n,x);	
}