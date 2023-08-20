#include<iostream>
using namespace std;
void MergeSort(int*, int, int);
void merge(int*, int, int);
int num;
int main()
{
    int m, n;
    cin >> m;
    for (int i = 0;i < m;i++)
    {
        cin >> n;
        num = 0;
        int a[50000];
        for (int j = 0; j < n; j++) cin >> a[j];
        MergeSort(a, 0, n - 1);
        cout << num << endl;
    }
    return 0;
}
void MergeSort(int a[], int x, int y)
{
    if (x >= y) return;
    MergeSort(a, x, (x + y) / 2);
    MergeSort(a, (x + y) / 2 + 1, y);
    merge(a, x, y);
}
void merge(int a[], int x, int y)
{
    int tmp[50000];
    int start1 = x, start2 = (x + y) / 2 + 1, k = x;
    while (start1 <= (x + y) / 2 && start2 <= y)
    {
        if (a[start1] <= a[start2])
        {
            tmp[k++] = a[start1++];
        }
        else
        {
            num += (x + y) / 2 - start1 + 1;
            tmp[k++] = a[start2++];
        }
    }
    if (start1 > (x + y) / 2)
        while (start2 <= y)
        {
            tmp[k++] = a[start2++];
        }
    if (start2 > y)
        while (start1 <= (x + y) / 2)
        {
            tmp[k++] = a[start1++];
        }
    for (int i = x; i <= y; i++) a[i] = tmp[i];
}