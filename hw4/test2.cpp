#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

using namespace std;

struct argument
{
	int a;
	int b[1000];
};

int main()
{
	struct argument arg;
	return 0;
}
