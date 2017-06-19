#include<iostream>
using namespace std;

int linearsearch(int a[],int n,int m);

int main()
{
	int N,M,a[100000];
	
	cin>>N;
	
	for(int i=0;i<N;i++)
	{
		cin>>a[i];
	}

	cin>>M;

	cout<< linearsearch(a,N,M);
}

int linearsearch(int a[],int n,int m)
{
	int found =0;
	
	for(int i=0;i<n;i++)
	{
		if(a[i]==m)
		{
			found = 1;
			return i;
		}
	}
	if(found==0)
		return -1;
}