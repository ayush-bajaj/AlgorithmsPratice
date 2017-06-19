#include<iostream>
using namespace std;

void myMerge(int arr[],int be,int en)
{
	int mid=(be+en)/2;
	int nLeft = mid - be + 1;
	int nRight = en - mid;
	int *left = new int[nLeft];
	int *right = new int[nRight];

	for(int i=0;i<nLeft;i++)
		left[i]=arr[i+be];

	for(int j=0;j<nRight;j++)
		right[j]=arr[j+mid+1];	

	int i=0; //Left array
	int j=0; //Right array
	int k=be; //Main array

	while(i<nLeft && j<nRight)
	{
		if(left[i]<right[j])
		{
			arr[k] = left[i];
			k++;
			i++;
		}

		else 
		{
			arr[k] = right[j];
			k++;
			j++;
		}

	}

	while(i<nLeft) arr[k++] = left[i++];
	while(j<nRight) arr[k++] = right[j++];
}

void mergesort(int arr[],int be,int en)
{
	if(be>=en)
	{
		return;
	}
	int mid=(be+en)/2;
	mergesort(arr,be,mid);
	mergesort(arr,mid+1,en);

	myMerge(arr,be,en);
}

int main()
{
	int a[100];
	int n;
	cin>>n;

	for(int i=0;i<n;i++)
		cin>>a[i];

	mergesort(a,0,n-1);

	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
}