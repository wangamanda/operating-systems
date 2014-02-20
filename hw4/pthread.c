#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
struct argument
{
	    int num;
	        char string[30];
};
int main()
{
	    int i,ret;
	        void *thread1_func(void *);
		    void *thread2_func(void *);
		        void *thread_return1,*thread_return2;/*???????????????*/
			    pthread_t thread1,thread2;
			        struct argument arg1,arg2;
				    arg1.num=1949;
				        strcpy(arg1.string,"dddd");
					    arg2.num=2009;
					        strcpy(arg2.string,"cccc");
						    pthread_create(&thread1,NULL,thread1_func,(void *)&arg1);
						        pthread_create(&thread2,NULL,thread2_func,(void *)&arg2);
							    for(i=0;i<=2;i++)
								        {
										        printf("mmmm!\n");
											        sleep(2);
												    }
							        ret=pthread_join(thread1,&thread_return1);/*?????????,????????*/
								    if(ret!=0)
									            printf("??pthread_join1!\n");
								        else
										        printf("pthread_joinfail%d\n",(int)thread_return1);
									    ret=pthread_join(thread2,&thread_return2);/*?????????,????????*/
									        if(ret!=0)
											        printf("pthread_joina!\n");
										    else
											            printf("pthread_join2%d\n",(int)thread_return2);
										        return 0;
}
void *thread1_func(void *arg)
{
	    int i;
	        struct argument *arg_thread1;/*?????????argument????????arg_thread1,??????????????*/
		    arg_thread1=(struct argument *)arg;
		        for(i=0;i<=3;i++)
				    {
					            printf("a1,a%d,%s\n",(*arg_thread1).num,(*arg_thread1).string);
						            sleep(2);
							        }
			    return (void *)123;
}
void *thread2_func(void *arg)
{
	    int i;
	        struct argument arg_thread2;/*???????argument??????arg_thread2,??????????????????????thread1_func???????????*/
		    arg_thread2=*(struct argument *)arg;    
		        for(i=0;i<=3;i++)
				    {
					            printf("b2,b%d,%s\n",arg_thread2.num,arg_thread2.string);
						            sleep(2);
							        }
			    return (void *)456;
}
/*********************** ??? pthread.c ???***************************/

