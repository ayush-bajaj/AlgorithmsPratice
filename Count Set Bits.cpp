#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int count=0;
	int temp=n;
	int div;
	for(div=2;div<=n;div=div*2);
	div=div/2;
	while(temp!=0)
	{
		if(temp>=div)
		{
			count++;
			temp=temp-div;
		}
		div=div/2;
		
	}	
	cout<<count;
}