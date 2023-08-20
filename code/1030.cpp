#include <iostream>
#include <vector>
using namespace std;
/*大体思路：遇到一个黑点就找离他最近的白点*/
int main() 
{
    long long t;
    cin >> t;
    for (int z = 0; z < t; z++) 
    {
        int n;
        cin >> n;
        vector<long long> whilte;
        vector<long long> black;
        for (int i = 1; i <= 2 * n; i++) 
        {
            long long data;
            cin >> data;
            if (data == 1) whilte.push_back(i);
            else black.push_back(i);
        }
        long long finalNum = 0;
        for (int i = 0; i < n; i++)
            finalNum += abs(whilte[i] - black[i]);
        cout << finalNum << endl;
    }
}