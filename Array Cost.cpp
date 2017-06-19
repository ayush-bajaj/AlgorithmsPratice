#include<iostream>
using namespace std;

int main()
{
	int n1,n2;
	int a[100000];
	cin>>n1;
	int count[10]={0,0,0,0,0,0,0,0,0,0};
	for(int i=0;i<n1;i++)
	{	
		cin>>n2;
		for(int j=0;j<n2;j++)
		{
			cin>>a[j];
		}
		for(int k=0;k<(n2-1);k++)
		{
			for(int l=k+1;l<n2;l++)
			{
				if(a[k]>a[l])
					count[i]++;
			}
		}
	}
	for(int i=0;i<n1;i++)
		cout<<count[i]<<"\n";
}