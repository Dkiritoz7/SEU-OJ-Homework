#include<iostream>
using namespace std;
int quickSort(int low,int high,int depth,int a[],int res[])
{
    if(low >= high) return 0;
    if(low+1 == high) 
    {
        if(a[low] > a[high]) swap(a[low],a[high]);
        return 0;
    }
    int p=low;
    for(int i=low;i<=high;i++)
    {
        if(a[i]<a[low]) 
        {
            p++;
            swap(a[p],a[i]);
        }
    }
    swap(a[low],a[p]);

    if(depth==1) {
        res[p] = a[p];    
    }
    if(depth==2) {
        for(int i=low; i<=high; i++) {
            res[i] = a[i];
        }
    }
    quickSort(low,p-1,depth+1,a,res);
    quickSort(p+1,high,depth+1,a,res);
    return 0;
}

int main() {
    int m;
    cin>>m;
    int n;
    int res[1000] = {0};
    int a[1000] = {0};
    for(int i=0; i<m; i++) 
    {
       cin>>n;
       for(int j=0;j<n;j++)
       {
            cin>>a[j];
       }
       quickSort(0,n-1,1,a,res);
       for(int j=0;j<n;j++)
       {
            cout<<res[j]<<" ";
       }
      cout<<endl;
    }
    return 0;
}
