#include<iostream>
#include<string>
using namespace std;

int main()
{
	string n;
	cin>>n;

	char *array = new char[20];

	int i;
	for(i=0;i<n.length();i++){
		if(n.at(i)!='0')
			array[i]= n.at(i);
		else array[i] = '5';
	}
	array[i]='\0';

	cout<<array;
}