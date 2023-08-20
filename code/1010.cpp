#include<iostream>
using namespace std;

void binSearch(int arr[],int x,int low,int high,int father)
{
    int middle=(low+high)/2;
    if(arr[middle]==x) 
    {
        cout<<"success, father is "<<father<<endl;
        return;
    }
    if(high>low)
    {
        if(arr[middle]>x) binSearch(arr,x,low,middle-1,arr[middle]);
        if(arr[middle]<x) binSearch(arr,x,middle+1,high,arr[middle]);
    }
    if(high<=low) cout<<"not found, father is "<<arr[low]<<endl;
    return;
}
int main()
{
    int m;
    cin>>m;
    int a[200001]={0};
    for(int i=0;i<m;i++)
    {
        int n,x;
        cin>>n>>x;
        for(int j=0;j<n;j++) cin>>a[j];
        binSearch(a,x,0,n-1,0);
    }
}