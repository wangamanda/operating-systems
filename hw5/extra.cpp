#include <iostream>
#include <pthread.h>

using namespace std;

int main()
{
	pthread_t thread[10];
	void *dealio(void *);
	int i;
	for (i = 0 ; i < 10 ; i ++)
	{
		pthread_create(&thread[i], NULL, dealio, NULL);
	}
	for (i = 0 ; i < 10 ; i ++)
	{
		pthread_join(thread[i], NULL);
	}
}

void *dealio(void *)
{
	while(1)
	{
		cout << "Thread ID is: " << pthread_self() << endl;
	}
	pthread_exit(NULL);
}
