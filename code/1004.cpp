#include<iostream>
#include<algorithm>
using namespace std;
void merge(int startIndex,int middleIndex,int endIndex,int soureArr[],int tempArr[])
{
    int k = startIndex;
    int i = startIndex;
    int j =  middleIndex+1;
    while(i<=middleIndex&&j<=endIndex)
    {
        if(soureArr[i]<soureArr[j]) 
        {
            tempArr[k++] = soureArr[i++];
        }
        else 
        {
            tempArr[k++] = soureArr[j++];
        }
    }
    while(i!=middleIndex+1) tempArr[k++] = soureArr[i++];
    while(j!=endIndex+1)    tempArr[k++] = soureArr[j++];
    for(int i=startIndex;i<=endIndex;i++)
    {
        soureArr[i]=tempArr[i];
    }
}
int leftCnt=0,rightCnt=0;
void mergesort(int startIndex,int endIndex,int sourceArr[],int tempArr[],int depth)
{
    int middleIndex = (endIndex + startIndex)/2 ;
    if(startIndex<endIndex)
    {
        mergesort(startIndex,middleIndex,sourceArr,tempArr,depth+1);
        mergesort(middleIndex+1,endIndex,sourceArr,tempArr,depth+1);
        if(depth>=3) merge(startIndex,middleIndex,endIndex,sourceArr,tempArr);
    }
    
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n; cin >> n;
		int arr[1000];
		int temp[1000] = { -1 };
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		mergesort(0, n-1, arr, temp, 1);
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	return 0;
}