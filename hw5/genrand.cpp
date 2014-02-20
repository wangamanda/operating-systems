#include <iostream>
#include <time.h>
#include <stdio.h>
#include <cstdlib>

using namespace std;

int main()
{
	int icnt;
	int ilimit;
	cin >> ilimit;
	cin >> icnt;
	//srand(icnt);
	for (int i = 0 ; i < icnt ; i ++)
	{
		cout << rand() % ilimit << endl;
	}
	return 0;
}
