#include<iostream>
#include<algorithm>
using namespace std;
int temp[50100]={0};
int cnt;
void queue_reverse(int a[],int start,int end)
{
    int k;
    if(start == end) 
    {
        temp[start] = a[start];
        return ;
    }
    int mid = (start + end )/2;
    queue_reverse(a,start,mid);
    queue_reverse(a,mid+1,end);
    int temp_start = start;
    k = start;
    int temp_mid = mid+1;
    while(temp_start<=mid&&temp_mid<=end)
    {
        if(a[temp_start] <= a[temp_mid]) temp[k++] = a[temp_start++];
        else
        {
            temp[k++] = a[temp_mid++];
            cnt += mid - temp_start + 1; 
        }
    }
    while(temp_start <= mid) temp[k++] = a[temp_start++];
    while(temp_mid <=end) temp[k++] = a[temp_mid++];
    for(int i = start;i<=end;i++) a[i] = temp[i];
}
int main()
{
    int M;
    cin>>M;
    for(int i=0;i<M;i++)
    {
        cnt = 0;
        int result;
        int a[50100];
        int N;
        cin>>N;
        for(int j = 1;j<=N;j++)
        {
            cin>>a[j];
        }
        queue_reverse(a,0,N);
        for(int j = 1;j<=N;j++)
        {
            // cout<<a[j]<<" ";
        }
        cout<<cnt<<endl;
    }
    return 0;
}