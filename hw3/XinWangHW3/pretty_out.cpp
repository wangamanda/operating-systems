#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	//	int a[n+1];
//	int i;
	int m = 0;
	int mypipe;//the read port of pipe, corresponding to pipe_fd[0] in problem4.cpp
	char buf[4096];
	
	mypipe = atoi(argv[1]);//the pipe parameter is argv[1]

	string str("");
	while(read(mypipe, buf, 4096)!=0)//read numbers in pipe into the buffer
	{
		int i = 0,j = 0;
		
		str += buf;
		memset(buf, 0, 4096);//every time after numbers are read from the buffer, clean the buffer
	}

	
	const char * split = " ";//split contents in buffer by " "
	
	strcpy(buf, str.c_str());
	char * p = strtok(buf, split);
	while (p != NULL)
	{
		cout << setw(7) << p;
		m++;
		if (m % 10 == 0)
			cout << endl;
		p = strtok(NULL, split);
	}
	cout <<endl;
	close(mypipe);//close the read port of pipe
}
