#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<cstring>
#include<string>
using namespace std;
int KMPFind(char* T, char* P, int k, int next[]);
void getNext(char* a, int *next);
int M, n, m;
char* T = new char[100001], * P = new char[100001];
int* nt = new int[100001];
int main()
{	
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> n>> m;
		int k = 0, num = 0;
		for (int j = 0; j < n; j++)
			cin >> T[j];
		for (int j = 0; j < m; j++)
			cin >> P[j];
		getNext(P, nt);
		while(k <= n-m )
		{
			int x = KMPFind(T, P, k, nt); 
			if (x != -1)
			{
				num++; 
				k = x + 1;
			}
			else break;
		}
		cout <<num<< endl;
	}
	return 0;
	
}
void getNext(char *a, int *next)
{
	int j = 0, k = -1;
	next[0] = -1;
	while (j < m)
		if (k == -1) {
			j++; k++; next[j] = k;
		}
		else {
			if (a[j] == a[k]) {
				j++; k++; next[j] = k;
			}
			else k = next[k];
		}
}
int KMPFind(char *T, char *P, int k, int *next)
{
	int posP = 0, posT = k;
	while (posP < m && posT < n)
		if (posP == -1 || P[posP] == T[posT])
		{
			posT++; posP++;
		}
		else posP = next[posP];
	if (posP < m) return -1;
	else return posT - m;
}
