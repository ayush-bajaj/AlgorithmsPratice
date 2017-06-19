#include<iostream>
using namespace std;

int rotatedsearch(int a[],int n,int x)
{
	int low=0;
	int high=n-1;

	while(low<=high)
	{
		int mid=(low+high)/2;

		if(a[mid]==x)
			return mid;

		if(a[low]<a[mid])
		{
			if(a[low]<=x && a[mid]>=x)
				high = mid-1;
			else
				low = mid+1;
		}

		else
		{
			if(a[mid]<=x && a[high]>=x)
				low = mid+1;

			else
				high = mid-1;
		}
	}

	return -1;
}

int main()
{
	int arr[]={5,6,7,1,2,3};
	int n= sizeof(arr)/sizeof(int);

	int x;
	cin>>x;

	cout<< rotatedsearch(arr,n,x);	
}