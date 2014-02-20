#include <iostream>
#include <iomanip>
using namespace std;

int sieve(int n, int *a)//calculate the prime numbers within the range 0~n
{
//	int n;
//	cin >> n;
//	int a[n+1];
	int i,j;
	a[0] = 0;
	a[1] = 0;

	for (i = 2 ; i <= n ; i ++)//initialize all members in the array to be 1
	{
		a[i] = 1;
	}

	for (i = 2 ; i <= n-1 ; i ++)//start with subscript 2 and working upward
	{
		for (j = i+1; j <= n ; j ++)
		{
			if (j%i == 0)//set 0 to elements whose subscript is the multiple of subscript for the element with value 
			{
				a[j] = 0;
			}
		}
	}
}

int print(int n, int *a)//print out the subscripts of elements whose values are 1, we get the primes
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
