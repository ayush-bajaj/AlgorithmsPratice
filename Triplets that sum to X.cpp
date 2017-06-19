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
			for(int k=i+2;k<n;k++)
			{
				if(arr[i]+arr[j]+arr[k]==x)
					cout<<"Triplet is "<<arr[i]<< " "<<arr[j]<< " "<<arr[k]<<"\n";
			}
		}
	}

}