#include<iostream>
#include <iomanip>
using namespace std;
/*每个桥断裂概率为pi,并且各个桥断的概率独立，所以每个桥对最后结果的贡献为pi/100，累加即可*/
int main() 
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) 
	{
		int N;
		cin >> N;
		double sum = 0;
		double num;
		for (int i = 0; i < N - 1; i++) 
		{
			cin >> num;
			sum += num/100;
		}
		cout << fixed << setprecision(6) << 1 + sum << endl;
	}
}