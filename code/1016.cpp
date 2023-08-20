#include<iostream>
#include<algorithm>
using namespace std;
void add_fun(int a[],int number,int result)
{
        int addResult;
        int start=1;
        int end = number;
        while(start < end)
        {
            addResult = a[start] + a[end];
            if(addResult>result) end--;
            if(addResult<result)
            {
                start++;
                end = number;
            }
            if(addResult == result)
            {
                cout<<"yes"<<endl;
                return ;
            }
        }
        /*for(int i = 1;i<=number;i++)
          {
            for(int j = number;j>i;j--)
                {
                    addResult = a[i] + a[j];
                    if(addResult)
                    if(addResult == result) 
                    {
                        cout<<"yes"<<endl; 
                        return ;
                    }
                }
        }*/
        cout<<"no"<<endl;
        return ;
}
int main()
{
    int M;
    cin>>M;
    for(int i = 0;i<M;i++)
    {
        int N,X;
        cin>>N;
        cin>>X;
        int data[50010];
        for(int i = 1;i<=N;i++) cin>>data[i];
        sort(data,data+N+1);
        add_fun(data,N,X);
    }
    return 0;
}