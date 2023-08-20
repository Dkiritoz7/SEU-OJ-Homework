#include<iostream>
#include<algorithm>
using namespace std;
void adjust(int low,int high,int a[])
{
    int p=high/2-1;
    for(;p>=0;p--)
    {
        int pos=p;
        while((a[2*pos+1]<a[pos]&&2*pos+1<=high-1)||(a[2*pos+2]<a[pos]&&2*pos+2<=high-1))
        {
             if(a[2*pos+1]<=a[2*pos+2]&&2*pos+1<=high-1)
             {
                swap(a[2*pos+1],a[pos]);
                pos=2*pos+1;
             }
             else if(a[2*pos+1]<a[pos]&&2*pos+1<=high-1&&2*pos+2>high-1)
             {
                swap(a[pos],a[pos*2+1]);
                pos=pos*2+1;
             }
             else if(a[2*pos+1]>a[2*pos+2]&&2*pos+1<=high-1&&2*pos+2<=high-1)
             {
                swap(a[pos],a[pos*2+2]);
                pos=pos*2+2;
             }
        }
    }
    return ;
}
int main()
{
	int T;
    int n;
	cin >> T;
    int a[1000]={0};
	for(int i=0; i<T; i++) 
    {
       cin>>n;
       for(int j=0;j<n;j++)
       {
            cin>>a[j];
       }
       adjust(0,n,a);
       for(int j=0;j<n;j++)
       {
            cout<<a[j]<<" ";
       }
      cout<<endl;
    }
	return 0;
}