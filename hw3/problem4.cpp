#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <cstring>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
using namespace std;

int pipe_fd[2];

int main()
{
	int n;
	while(cin >> n)
	{
		int a[n+1];
		pid_t pid[2];
		char *argv1[4];
		char *argv2[3];
		char buf[1001];

		if (pipe(pipe_fd) < 0)
		{
			cout << "Fail to create a pipe!" << endl;
		}

		pid[0] = fork();
		if (pid[0] < 0)
		{
			cout << "Fail to fork the first child process!" << endl;
		}
		else if (pid[0] == 0)
		{
			char temp[64];
	//		cout << "This is the first child process." << endl;
	//		cout << "pid of the fist child:" << getpid() << endl;
	//		cout << "pid of the parent:" << getppid() << endl;
			close(pipe_fd[0]);
			argv1[0] = (char *)calloc(strlen("sieve")+1, sizeof(char));
			strcpy(argv1[0], "sieve");
			sprintf(temp, "%d" , n);
			argv1[1] = (char *)calloc(strlen(temp)+1, sizeof(char));
			strcpy(argv1[1],temp);
			sprintf(temp, "%d", pipe_fd[1]);
			argv1[2] = (char *)calloc(strlen(temp)+1, sizeof(char));
			strcpy(argv1[2], temp);
			argv1[3] = 0;
		//	sprintf(buf,"%d", 777);
		//	int cc;
		//	cc=write(pipe_fd[1],buf,strlen(buf));
		//	cout << cc;
			execv("sieve",argv1);
			cout << "execv error!" << endl;
		}
		else if (pid[0] > 0)
		{
		//	waitpid(-1, NULL, 0);
	//		cout << "This is the parent process." << endl;
	//		cout << "pid of the parent:" << getpid() << endl;
	//		cout << "pid of the grandparent:" << getppid() << endl;
			pid[1] = fork();
			if (pid[1] < 0)
			{
				cout << "Fail to fork the second child process!" << endl;
			}
			else if (pid[1] == 0)
			{
				char temp[64];
			//	cout << "This is the second child process." << endl;
	//			cout << "pid of the second child:" << getpid() << endl;
	//			cout << "pid of the parent:" << getppid() << endl;
				close(pipe_fd[1]);
				argv2[0] = (char *)calloc(strlen("pretty_out")+1, sizeof(char));
				strcpy(argv2[0], "pretty_out");
				sprintf(temp, "%d" , pipe_fd[0]);
				argv2[1] = (char *)calloc(strlen(temp)+1, sizeof(char));
				strcpy(argv2[1], temp);
			//	cout << "mmm" << endl;
			//	cout << argv1[0] << argv1[1] << argv1[2] << endl;
				argv2[2] = 0;
			//	int dd;
			//	dd = read(pipe_fd[0],buf,1001);
			//	cout << "dd:" << dd;
			//	cout <<"buf:"<< buf << endl;
				execv("pretty_out",argv2);
				cout << "execv error!" << endl;
			}
			else if (pid[1] > 0)
			{
				close(pipe_fd[0]);
				close(pipe_fd[1]);
				waitpid(-1, NULL, 0);
	//			cout << "This is the parent process." << endl;
	//			cout << "pid of the parent:" << getpid() << endl;
	//			cout << "pid of the grandparent:" << getppid() << endl;
			}
		}
	}
	return 0;
}
