#include <iostream>
#include <sys/time.h>
#include <stdio.h>
#include <math.h>

using namespace std;

#define MSIZE 20000
static int matrix[MSIZE][MSIZE];//step(1)

int main()
{
	hrtime_t time_start;
	long long time_out;
	hrtime_t time_end;
	pid_t fpid;
	int i1,j1,i2,j2;
	int i,j;

	fpid = fork();//step(2)
	time_start = gethrtime();//step(3)
	for (i = 0 ; i < 1000 ; i ++)//(4)
	{
		for (j = 0 ; j < 1000 ; j ++)//(5)(6)
		{
			i1 = rand()%MSIZE;
			j1 = rand()%MSIZE;
			i2 = rand()%MSIZE;
			j2 = rand()%MSIZE;
	//		matrix[i1][j1] = matrix[i2][j2];
		}
		time_end = gethrtime();//(7)
		time_out = (time_end - time_start);
		if (time_out/pow(10,9) > 10)
		{
			cout << "The execution time is more than 10sec." << endl;
			cout << time_out << endl;
			exit(-1);
		}
	}
	if(i == 1000 && j == 1000)//(8)
	{
		cout << "execution time in inanosecond:" << time_out << endl;
		cout << "execution time in second:" << time_out/pow(10,9) << endl;
	}
		/*
	if (fpid < 0) //fork error
	{
		cout << "fork error." << endl;
	}
	else if (fpid == 0)//child process
	{
	}
	else//father process
	{
	}
	*/
	return 0;
}
