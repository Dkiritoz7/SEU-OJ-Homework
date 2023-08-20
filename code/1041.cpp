#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
int main()
{
    int nums;
    cin>>nums;
    for(int z = 0;z<nums;z++)
    {
        int n,m;
        cin>>n>>m;
        double *nums1 = new double[n];
        double *nums2 = new double[m];
        for(int i = 0;i<n;i++) cin>>nums1[i];
        for(int i = 0;i<m;i++) cin>>nums2[i];
        int start1 = 0,start2 = 0,k=0;
        double finalNum;
        double *tmp = new double[n+m];
        while(start1<n&&start2<m)
        {
            if(nums1[start1]<nums2[start2])
            {
                tmp[k++] = nums1[start1];
                start1++;
            }
            else{
                tmp[k++] = nums2[start2];
                start2++;
            }
        }
        while(start1<=n-1)
        {
            tmp[k++] = nums1[start1];
            start1++;
        }
        while(start2<=m-1)
        {
            tmp[k++] = nums2[start2];
            start2++;
        }
        if((m+n)%2 == 0)
        {
            cout<< (tmp[(m + n) / 2 - 1] + tmp[(m + n) / 2]) * 0.5 <<endl; 
        }
        else{
            cout<< 1.0 * tmp[(m + n) / 2]<<endl;
        }
    }
    return 0;
}