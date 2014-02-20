#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <cstring>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
using namespace std;

int pipe_fd[2];//define a pipe

int main()
{
	int n;//define the range
	while(cin >> n)//input number to calculate primes until EOF
	{
		int a[n+1];//define an array
		pid_t pid[2];//difine process id of two child processes
		char *argv1[4];//parameters of execv in first child
		char *argv2[3];//parameters of execv in second child
		char buf[1001];

		if (pipe(pipe_fd) < 0)//if pipe fails
		{
			cout << "Fail to create a pipe!" << endl;
		}

		pid[0] = fork();//fork the first child
		if (pid[0] < 0)//if fork fails
		{
			cout << "Fail to fork the first child process!" << endl;
		}
		else if (pid[0] == 0)//in the first child process
		{
			char temp[64];
			close(pipe_fd[0]);//the first child is to write numbers, so close the read port
			argv1[0] = (char *)calloc(strlen("sieve")+1, sizeof(char));
			strcpy(argv1[0], "sieve");//the first parameter argv1[0] stores name of executable program
			sprintf(temp, "%d" , n);
			argv1[1] = (char *)calloc(strlen(temp)+1, sizeof(char));
			strcpy(argv1[1],temp);//the second parameter argv1[1] stores number n
			sprintf(temp, "%d", pipe_fd[1]);			
			argv1[2] = (char *)calloc(strlen(temp)+1, sizeof(char));
			strcpy(argv1[2], temp);//the third parameter argv1[2] stores the write port of pipe pipe_fd[1]
			argv1[3] = 0;
			execv("sieve",argv1);//use program sieve to replace first child process
			cout << "execv error!" << endl;//if execv finihes, some error occur
		}
		else if (pid[0] > 0)//in parent process
		{
			pid[1] = fork();//fork another child
			if (pid[1] < 0)//if fork fails
			{
				cout << "Fail to fork the second child process!" << endl;
			}
			else if (pid[1] == 0)//in the second child process
			{
				char temp[64];
				close(pipe_fd[1]);//the second child is to read from pipe, so close the write port of pipe
				argv2[0] = (char *)calloc(strlen("pretty_out")+1, sizeof(char));
				strcpy(argv2[0], "pretty_out");//the first parameter argv2[0] stores the name of executable program in second child process
				sprintf(temp, "%d" , pipe_fd[0]);
				argv2[1] = (char *)calloc(strlen(temp)+1, sizeof(char));
				strcpy(argv2[1], temp);//the second parameter argv2[1] stores the read port of pipe
				argv2[2] = 0;
				execv("pretty_out",argv2);
				cout << "execv error!" << endl;
			}
			else if (pid[1] > 0)//in parent process, close both ports of pipe
			{
				close(pipe_fd[0]);
				close(pipe_fd[1]);
				waitpid(-1, NULL, 0);
			}
		}
	}
	return 0;
}
