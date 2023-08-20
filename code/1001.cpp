#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	cin>>n;
	char c[101];
	cin.getline(c,100);
	for(int i=0;i<n;i++)
	{
		int count=0;
		cin.getline(c,100);
		for(int k=0;c[k]!='\0';k++)
		{
			if('0'<=c[k]&&c[k]<='9') count++;
		}
		cout<<count<<endl;
	}
	return 0;
}