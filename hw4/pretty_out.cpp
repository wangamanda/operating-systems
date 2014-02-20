#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	//	int a[n+1];
//	int i;
	int m = 0;
	int mypipe;
	char buf[4096];
	
//	cout << argv[0] << argv[1] << argv[2] << endl;
	mypipe = atoi(argv[1]);
//	while(read(mypipe, buf, 8*sizeof(char))!= 0)
//	{
//
	string str("");
	while(read(mypipe, buf, 4096)!=0)
	{
		int i = 0,j = 0;
		
		str += buf;
		memset(buf, 0, 4096);
	}

	
	const char * split = " ";
	
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
	close(mypipe);
}
