#include<iostream>
#include<algorithm>
using namespace std;

bool search(int a[],int n,int m)
{

	int low=0;
	int high=n-1;
	while(low<=high)
	{
		int mid=(low+high)/2;
		if(a[mid]==m)
		{
			return true;
		}
		else if(a[mid]>m)
		{
			high=mid-1;	
		}
		else
		{
			low=mid+1;
		}
	}
	return false;
}

int main()
{
	int n;
	cin>>n;
	int a[1000];
	for(int i=0;i<n;i++)
		cin>>a[i];

	sort(a,a+n);

	int m;
	cin>>m;

	if(search(a,n,m))
		cout<<"true";
	else cout<<"false";
}