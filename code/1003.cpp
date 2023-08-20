#include<iostream>
using namespace std;
int main()
{
	int m,n;
	int a[1001]={0};
	cin>>m;
	for(int i=0;i<m;i++)
	{
		cin>>n;
		for(int j=0;j<n;j++)
		{
			cin>>a[j];
		}
		for(int j=0;j<n-1;j++)
		{
			for(int k=0;k<n-j-1;k++)
			{
				if(a[k]>a[k+1]) swap(a[k],a[k+1]);
			}
		}
		cout<<a[1];
		cout<<endl;
	}
	return 0;	
}