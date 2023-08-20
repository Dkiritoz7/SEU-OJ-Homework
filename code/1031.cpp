#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
const double minINF = 0.00000000001; //题目要求最小误差
bool hasCover(double px, double py, double* cover); //判断这个点是否可以被覆盖到
int MyCompare(const void* p1, const void* p2);  //排序的话是要以这个船最远基站的x值排序
double point[10001][2]; //船抽象为点
double cover[10001]; //已存基站位置
int num;
int d;
int main() 
{
    int m;
    cin >> m;
    for (int z = 0; z < m; z++) 
    {
        int n;
        num = 0; //基站个数
        cin >> n >> d;
        for (int x = 0; x < n; x++) cin >> point[x][0] >> point[x][1];
        qsort(point, n, sizeof(double) * 2, MyCompare);
        for (int k = 0; k < n; k++) {
            if (!hasCover(point[k][0], point[k][1], cover)) //未覆盖，添基站，加num
            {
                cover[num] = point[k][0] + sqrt(d * d - point[k][1] * point[k][1]);
                num++;
            }
        }
        cout << num << endl;
    }
    return 0;
}
bool hasCover(double px, double py, double* cover) 
{
    for (int i = 0; i < num; i++) 
    {
        double temp = (px - cover[i]) * (px - cover[i]) + py * py - d * d;
        if (temp <= minINF) return true;
    }
    return false;
}
int MyCompare(const void* p1, const void* p2) 
{
    double temp =
        ((double*)p1)[0] + sqrt(d * d - ((double*)p1)[1] * ((double*)p1)[1]) -
        (((double*)p2)[0] + sqrt(d * d - ((double*)p2)[1] * ((double*)p2)[1]));
    if (-minINF <= temp && temp <= minINF) return 0;
    else if (temp < 0)return -1;
    else return 1;
}
