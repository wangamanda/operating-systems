#include <iostream>
#include <iomanip>
using namespace std;

int sieve(int n, int *a)
{
//	int n;
//	cin >> n;
//	int a[n+1];
	int i,j;
	a[0] = 0;
	a[1] = 0;

	for (i = 2 ; i <= n ; i ++)
	{
		a[i] = 1;
	}

	for (i = 2 ; i <= n-1 ; i ++)
	{
		for (j = i+1; j <= n ; j ++)
		{
			if (j%i == 0)
			{
				a[j] = 0;
			}
		}
	}
}

int print(int n, int *a)
{
//	int a[n+1];
	int i;
	int m = 0;
	for (i = 2 ; i <= n ; i ++)
	{
		if(a[i] == 1)
		{
			cout  <<setw(7)<< i;
			m ++;
			
			if(m%10 == 0)
			{
				cout << endl;
				m = 0;
			}
		}
	}
	cout << endl;
}

int main()
{
		int n;
		while(cin>>n){
		int a[n+1];
		sieve(n,a);
		print(n,a);
	}
	return 0;
}
