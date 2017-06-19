#include<iostream>
using namespace std;

int main()
{
	//Input array
	int n;
	int arr[100];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];

	//Input sum
	int x; 
	cin>>x;

	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(arr[i]+arr[j]==x)
				cout<<"Doublet is "<<arr[i]<< " "<<arr[j]<<"\n";
		}
	}

}