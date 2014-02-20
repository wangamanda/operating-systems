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
	
	pthread_t thread1, thread2, thread3;// define three threads
	
	int ret1, ret2, ret3; //return values of three threads
	void *thief(void *);

	errno_create1 = pthread_create(&thread1, &attr, thief, NULL);//create thread1
	if (errno_create1 != 0)
	{
		cout << "Creation of thread1 is unsuccessful." << endl;
	}
	errno_create2 = pthread_create(&thread2, &attr, thief, NULL);//create thread2
	if (errno_create2 != 0)
	{
		cout << "Creation of thread2 is unsuccessful." << endl;
	}
	errno_create3 = pthread_create(&thread3, &attr, thief, NULL);//create thread3
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

void* thief (void *)//thief function which is operated by all three threads
{
	int n = 0;//initialize own account to 0
	int sum ;//sum of bank account
	int total = 0;//threads' own balance
	ifstream infile;
	ofstream outfile;
	while(1)
	{
	infile.open("bankaccount.txt");//open the bank account
	if (!infile.is_open())
	{
		cout << "Error opening file." << endl;
		exit(1);
	}
	infile >> sum;//read the amount from bank account
	infile.close();
	if (sum > 0)//when the amount is larger than $1, steal one half to its own account
	{
		total = total + sum/2 + 1;
		sum = sum - sum/2 - 1;
		outfile.open("bankaccount.txt");
		outfile << sum << endl;
		outfile.close();
	}
	else
		break;
	}
	n = total;
	cout << "thread ID: " << pthread_self() << ". Total amount that have stolen:" << n << endl;
	pthread_exit(NULL);
}
