#include<iostream>
#include<vector>
#include<string>
using namespace std;

string largestString(const vector<string> &vs)
{
	int maxCount = 0;
	string max="";

	for(int i=0;i<vs.size();i++)
	{
		if(vs[i].length()>maxCount)
		{
			maxCount=vs[i].length();
			max = vs[i];
		}
	}

	return max;
}

int main()
{
	int n;
	cin>>n;
	cin.ignore();
	string s;
	vector<string> vs;

	for(int i=0;i<n;i++)
	{
		getline(cin,s);
		vs.push_back(s);
	}

	cout<< largestString(vs)<<" "<<largestString(vs).length();
}