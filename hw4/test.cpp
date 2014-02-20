#include <iostream>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

struct argument
{
	int a;
	int b[10];
};

int main()
{
//	int ret1, ret2;//test whether threads are created successfully or not
//	int i;
//	void *thread1_func(void *);//thread1
//	void *thread2_func(void *);//thread2
//	void *thread1_return, *thread2_return;//return value of the two threads
//	pthread_t thread1, thread2;//define two threads
struct argument arg;
	/*	while(1)
	{
		pthread_create(&thread1, NULL, thread1_func, (void*)&arg1);
		pthread_create(&thread2, NULL, thread2_func, (void*)&arg2);
		ret1 = pthread_join(thread1, NULL);
		if (ret1 != 0)
		{
			cout << "Creation of thread1 failed!" << endl;
		}
		else
		{
			arg2.num = arg1.num;
			for (i = 0 ; i <= arg1.num ; i ++)
			{
				arg2.a[i] = arg1.a[i];
			}
		}
		ret2 = pthread_join(thread2, NULL);
		if (ret2 != 0)
		{
			cout << "Creation of thread2 failed!" << endl;
		}
		
	}*/
	return 0;
}


