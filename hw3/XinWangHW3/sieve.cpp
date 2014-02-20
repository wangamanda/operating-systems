#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

using namespace std;

int main(int argc, char *argv[])
{
	int n;
//	cin >> n;
	n = atoi(argv[1]);//The range of the primes is parsed by parameter argv[1]
	int *a;//a is the array as in problem 3
	a = (int *)calloc(n+1,sizeof(int));//allocate memory to a dinamically
	int mypipe;//the write port of pipe
	int i,j;
	a[0] = 0;
	a[1] = 0;
	char buf[4096];
	//The following prime calculation and sieve process is exactly the same as in problem 3
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

	for (i = 2 ; i <= n ; i ++)
	{
		if (a[i] == 1)
		{
			sprintf(buf, "%d ", i);
			mypipe = atoi(argv[2]);
			if(write(mypipe, buf, strlen(buf))== -1)//write contents to the write port of pipe
			{
				cout << "write error!" << endl;
			}
			
		}
	}
	close(mypipe);//close the pipe after writing is finished
}


