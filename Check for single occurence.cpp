#include<iostream>
using namespace std;
#include<algorithm>

int main()
{
	//Input array
	int n;
	int arr[100];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];

	sort(arr,arr+n);

	for(int i=0;i<n;i++)
	{
		if (arr[i+1]==arr[i])
		{
			int k=arr[i];
			while(arr[i]==k) i++;
			i--;
		}
		else 
			cout<<arr[i];
	}
}