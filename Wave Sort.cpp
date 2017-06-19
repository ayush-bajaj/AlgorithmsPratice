#include<iostream>
using namespace std;

void wavesort(int a[],int n)
{
	for(int i=0;i<n;i +=2)
	{
		if(i-1>0 && a[i]<a[i-1])
			swap(a[i],a[i-1]);

		if(i+1<n && a[i]<a[i+1])
			swap(a[i],a[i+1]);
	}
}

int main()
{
	int n;
	cin>>n;
	int a[100];

	for(int i=0;i<n;i++)
		cin>>a[i];

	wavesort(a,n);

	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";		
}