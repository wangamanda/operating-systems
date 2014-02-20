#include <iostream>
#include <string.h>
#include <iomanip>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <unistd.h>
//#include <stdlib.h>

extern char *optarg;
extern int optind;

using namespace std;

int main(int argc, char *argv[])
{
	DIR *dp;
	char filename[256][256];
	int rank[256];
	int depth = 1;
	struct dirent *entry;
	struct stat stt;
	int len = 0;
	int i,j;
	int k = 0;
	char ch;
	int l_flag = 0;
	int a_flag = 0;
	int R_flag = 0;
	
	while ((ch = getopt(argc, argv, "alR")) != -1)
	{
		case 'a':
			a_flag = 1;
			break;
		case 'l':
			l_flag = 1;
			break;
		case 'R':
			R_flag = 1;
			break;
		default:
			cout << "This parameter is illegal." << endl;
			return 1;
	}
	//	ch = getopt(argc, argv, "alR");
	if ((ch = getopt(argc, argv, "alR")) == -1)
	{
		if (argv[1] == NULL)
		{
			dp = opendir(".");
		}
		else
		{
			dp = opendir(argv[1]);
		}

		if(dp == NULL)
		{
			cout << "Error in open dir." << endl;
			return 1;
		}
		while(entry = readdir(dp))
		{
			if (strncmp(entry->d_name,".",1) == 0)
				continue;
			if(stat(entry->d_name,&stt) >= 0 && S_ISDIR(stt.st_mode))
			{
			//	cout << setw(8) << entry->d_name << "/" << "\t";
				strcpy(filename[len++],entry->d_name);
				i = len - 1;
				strcat(filename[i],"/");
			//	cout << entry->d_name << "a";
			}
			else
				strcpy(filename[len++],entry->d_name);
		}
		for (i = 0 ; i < len ; i ++)
		{
			rank[i] = 0;
		}
		for (i = 0 ; i < len ; i ++)
		{
			for (j = 0 ; j < len ; j ++)
			{
				int temp;
				temp = strcmp(filename[i],filename[j]);
				if (temp > 0)
				{
					rank[i] += 1;
				}
				else if (temp < 0)
				{
					rank[i] = rank[i];
				}
				else if (temp == 0)
				{
				//	cout << "Same rank is illegal in a directory." << endl;
					;
				}
			}
		}
		for (i = 0 ; i < len ; i ++)
		{
			for (j = 0 ; j < len ; j ++)
			{
				if (rank[j] == i)
				{
					cout << setiosflags(ios::left) << setw(5) << filename[j] << "\t";
					k ++;
				}
				if (k == 6)
				{
					cout << endl;
					k = 0;
				}
			}
		}
		cout << endl;
		closedir(dp);
	}

	while((ch) != -1)
	{
		switch(ch){
			case 'a':
				dp = opendir(".");
				if(dp == NULL)
				{
					cout << "Error in open dir." << endl;
					return 1;
				}
				while(entry = readdir(dp))
				{
					if(stat(entry->d_name,&stt) >= 0 && S_ISDIR(stt.st_mode))
					{
						strcpy(filename[len++],entry->d_name);
						i = len - 1;
						strcat(filename[i],"/");
					}
					else
						strcpy(filename[len++],entry->d_name);
				}
				for (i = 0 ; i < len ; i ++)
				{
					rank[i] = 0;
				}
				for (i = 0 ; i < len ; i ++)
				{
					for (j = 0 ; j < len ; j ++)
					{
						int temp;
						temp = strcmp(filename[i],filename[j]);
						if (temp > 0)
						{
							rank[i] += 1;
						}
						else if (temp < 0)
						{
							rank[i] = rank[i];
						}
						else if (temp == 0)
						{
							;
						}
					}
				}
				for (i = 0 ; i < len ; i ++)
				{
					for (j = 0 ; j < len ; j ++)
					{
						if (rank[j] == i)
						{
							cout << setiosflags(ios::left) << setw(5) << filename[j] << "\t";
							k ++;
						}
						if (k == 6)
						{
							cout << endl;
							k = 0;
						}
					}
				}
				cout << endl;
				closedir(dp);
				break;
			case 'l':
				break;
			case 'R':
				break;
//			default:
//				dp = opendir(".");
		}
		ch = getopt(argc, argv, "alR");
	}
		return 0;
}
