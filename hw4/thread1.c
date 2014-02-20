/* if you want to compile for C, the following statement should be:
    #define COMPILE_FOR_C
        If you want to compile for C++, the following statement should be:
         #undef COMPILE_FOR_C */

#define COMPILE_FOR_C

#include <pthread.h>
#include <stdio.h>

#ifdef COMPILE_FOR_C
 void *howdy();
#else
 void *howdy(void *);
#endif

 main() {
	 pthread_t	tid;
	 pthread_attr_t	attr;

	 	pthread_attr_init(&attr);
			pthread_create(&tid, &attr, howdy, 0);

				pthread_join(tid, NULL);
					printf("Hey, not yet!\n");

 }


#ifdef COMPILE_FOR_C
void *howdy() {
#else
	void *howdy(void *a) {
#endif

			printf("Howdy, Lehigh!\n");
				pthread_exit(0);
	}

