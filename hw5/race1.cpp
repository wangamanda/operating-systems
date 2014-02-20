#include <iostream>
#include <pthread.h>
#include <iomanip>
#include <stdlib.h>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
	int n = 1000;//the initial amount ot bank account
	int errno_create1, errno_create2, errno_create3;//error message of creating threads
	int errno_join1, errno_join2, errno_join3;//error message of waiting for threads
	const char filename[] = "bankaccount.txt";//the bank account file
	ofstream o_file;
//	ifstream i_file;
	o_file.open(filename);//open and write amount to bank account file
	o_file << n << endl;
	o_file.close();//close the file after writing
	
	pthread_attr_t attr;//attributes

	pthread_attr_init(&attr);//initializing attributes
//	pthread_attr_init(&attr2);
//	pthread_attr_init(&attr3);
	
	pthread_t thread1, thread2, thread3;// define three threads
	int ret1, ret2, ret3; //return values of three threads
	void *thread1_func(void *);
	void *thread2_func(void *);
	void *thread3_func(void *);

	errno_create1 = pthread_create(&thread1, &attr, thread1_func, NULL);//create thread1
	if (errno_create1 != 0)
	{
		cout << "Creation of thread1 is unsuccessful." << endl;
	}
	errno_create2 = pthread_create(&thread2, &attr, thread2_func, NULL);//create thread2
	if (errno_create2 != 0)
	{
		cout << "Creation of thread2 is unsuccessful." << endl;
	}
	errno_create3 = pthread_create(&thread3, &attr, thread3_func, NULL);//create thread3
	if (errno_create3 != 0)
	{
		cout << "Creation of thread3 is unsuccessful." << endl;
	}
	
	errno_join1 = pthread_join(thread1, NULL);//wait for thread1
	if (errno_join1 != 0)
	{
		cout << "Join of thread1 fails." << endl;
	}
	errno_join2 = pthread_join(thread2, NULL);//wait for thread2
	if (errno_join2 != 0)
	{
		cout << "Join of thread2 fails." << endl;
	}
	errno_join3 = pthread_join(thread3, NULL);//wait for thread3
	if (errno_join3 != 0)
	{
		cout << "Join of thread3 fails." << endl;
	}

	return 0;
}

int thief (int n)//thief function which is operated by all three threads
{
	n = 0;//initialize own account to 0
	int sum ;//sum of bank account
	int total = 0;//threads' own balance
	ifstream infile;
	ofstream outfile;
	infile.open("bankaccount.txt");//open the bank account
	if (!infile.is_open())
	{
		cout << "Error opening file." << endl;
		exit(1);
	}
	infile >> sum;//read the amount from bank account
	infile.close();
	while (sum > 1)//when the amount is larger than $1, steal one half to its own account
	{
		total = total + sum/2;
		sum = sum - sum/2;
		outfile.open("bankaccount.txt");
		outfile << sum << endl;
		outfile.close();
		infile.open("bankaccount.txt");
		if (!infile.is_open())
		{
			cout << "Error opening file." << endl;
			exit(1);
		}
		infile >> sum;
		infile.close();
	}
	if (sum == 1)// when the remaining amount is $1, take it directly and add to its own account
	{
		total = total + sum;
		sum = sum - 1;
		outfile.open("bankaccount.txt");
		outfile << sum << endl;
		outfile.close();
	}
	else
	{
		cout << "The balance is zero."  << endl;	
	}
	n = total;
	return n;
}

void * thread1_func(void * )//thread1
{
	int own_balance1;
	own_balance1 = thief(own_balance1);
	cout << "thread ID: " << pthread_self() << ". Total amount that have stolen:" << own_balance1 << endl;
	pthread_exit(NULL);
}

void * thread2_func(void * )//thread2
{
	int own_balance2;
	own_balance2 = thief(own_balance2);
	cout << "thread ID: " << pthread_self() << ". Total amount that have stolen:" << own_balance2 << endl;
	pthread_exit(NULL);
}

void * thread3_func(void * )//thread3
{
	int own_balance3;
	own_balance3 = thief(own_balance3);
	cout << "thread ID: " << pthread_self() << ". Total amount that have stolen:"  << own_balance3 << endl;
	pthread_exit(NULL);
}
