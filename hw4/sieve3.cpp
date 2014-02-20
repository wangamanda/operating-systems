#include <iostream>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

struct argument
{
	int num;
	int a[1200];
};

int main()
{
	pthread_t thread1, thread2;//define two threads
	struct argument arg;


	while(cin>>arg.num)
	{

		int ret1, ret2;//test whether threads are created successfully or not
		int i;
		void *thread1_func(void *);//thread1
		void *thread2_func(void *);//thread2
//	void *thread1_return, *thread2_return;//return value of the two threads

		pthread_create(&thread1, NULL, thread1_func, (void*)&arg);
		ret1 = pthread_join(thread1, NULL);
		if (ret1 != 0)
		{
			cout << "Creation of thread1 failed!" << endl;
		}
		pthread_create(&thread2, NULL, thread2_func, (void*)&arg);
		ret2 = pthread_join(thread2, NULL);
		if (ret2 != 0)
		{
			cout << "Creation of thread2 failed!" << endl;
		}
	}
	return 0;
}

void *thread1_func(void *arg)
{
	int n;
	int i,j;
	int a[1200];
	a[0] = 0;
	a[1] = 0;
	struct argument * arg_thread1;
	arg_thread1 = (struct argument *)arg;
	n = arg_thread1->num;
//	a = arg_thread1 -> a;

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
	for (i = 0 ; i <= n ; i ++)
	{
		arg_thread1->a[i] = a[i];
	}
	
}

void *thread2_func(void *arg)
{
	int i;
	int n;
	int m = 0;
	int a[1200];
	struct argument *arg_thread2;

	arg_thread2 = (struct argument *)arg;

	n = arg_thread2->num;

	for (i = 2 ; i <= n ; i ++)
	{
		a[i] = arg_thread2->a[i];
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

