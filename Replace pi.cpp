#include<iostream>
using namespace std;

void shift(char arr[],int be)
{
	int j;
	for(j=be;arr[j]!='\0';j++);
	for(int i=j;i>=be;i--)
		arr[i+2]=arr[i];
}

void replacepi(char arr[],int be)
{
	if(arr[be]=='\0')
	{
		return;
	}
	if(arr[be]=='p' && arr[be+1]=='i')
	{
		shift(arr,be+2);
		arr[be]='3';
		arr[be+1]='.';
		arr[be+2]='1';
		arr[be+3]='4';
		replacepi(arr,be+4);
	}
	else
		replacepi(arr,be+1);
}

int main()
{
	char a[100];
	cin>>a;
	replacepi(a,0);
	cout<<a;
}