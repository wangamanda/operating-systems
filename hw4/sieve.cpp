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
	n = atoi(argv[1]);
	int *a;
	a = (int *)calloc(n+1,sizeof(int));
	int mypipe;
	int i,j;
	a[0] = 0;
	a[1] = 0;
	char buf[4096];

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
			if(write(mypipe, buf, strlen(buf))== -1)
			{
				cout << "write error!" << endl;
			}
			
		}
	}
	close(mypipe);
}


