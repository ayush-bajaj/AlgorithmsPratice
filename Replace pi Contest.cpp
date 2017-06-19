#include<iostream>
#include<cstring>
using namespace std;

void shift(char arr[],int be)
{
	int j;
	for(j=be;arr[j]!='\0';j++)
	{
		arr[j-2]=arr[j];
	}
	arr[j-2]=arr[j];
}

void replacepi(char arr[],int be)
{
	if(arr[be]=='\0' || arr[be+1]=='\0' || arr[be+2]=='\0' || arr[be+3]=='\0')
	{
		return;
	}
	if(arr[be]=='3' && arr[be+1]=='.' && arr[be+2]=='1' && arr[be+3]=='4')
	{
		shift(arr,be+4);
		arr[be]='p';	
		arr[be+1]='i';
		replacepi(arr,be+2);
	}
	else
		replacepi(arr,be+1);
}

int main()
{
	int n;
	cin>>n;
	cin.ignore();
	char a[100];
	char b[1000][100];
	for(int i=0;i<n;i++)
	{
		cin.getline(a,100);
		replacepi(a,0);
		strcpy(b[i],a);
	}

	for(int i=0;i<n;i++)
	{
		cout<<b[i]<<endl;
	}
}