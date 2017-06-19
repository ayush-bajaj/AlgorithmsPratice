#include<iostream>
using namespace std;

int binarysearch(int a[],int n,int m);

int main()
{
	int N,M,a[100000];
	
	cin>>N;
	
	for(int i=0;i<N;i++)
	{
		cin>>a[i];
	}

	cin>>M;

	cout<< binarysearch(a,N,M);
}

int binarysearch(int a[],int n,int m)
{
	int low=0;
	int high=n-1;
	int mid=(low+high)/2;
	while(low<=high)
	{
		if(a[mid]==m)
		{
			
			return mid;
		}
		else if(a[mid]>m)
		{
			high=mid-1;
			mid=(low+high)/2;
		}
		else
		{
			low=mid+1;
			mid=(low+high)/2;
		}
	}
	return(-1);
	
}