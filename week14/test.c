#include "my.h"
#define NUM 4
#define NUM_THREADS 4

struct info{
	int no;
	int n;
};
void hello(void *t)
{
	pthread_t my_tid;
	struct info *y;
	int s=0;
	y=(struct info *)(t);
	for(int i=0;i<=y->n;i++)
		s+=i;
	my_tid=pthread_self();
	printf("\t thread %d: my tid is %lx,hello world\n",(int)y->no+1,my_tid);
	printf("\t thread %d: sum 1 to  %d is %d \n",(int)y->no+1,y->n,s);
}
int main()
{
	pthread_t tid;
	struct info a[4];
	int rv,t;
	for(t=0;t<NUM_THREADS;t++)
	{
	a[t].no=t;
	a[t].n=100*(t+1);
	rv=pthread_create(&tid,NULL,(void*(*)())hello,(void*) &a[t]);
	if(rv!=0)
	{
		printf("thread create failed \n");
		return -1;

	}
	printf("create thread %lx\n",tid);

	}
printf(" see you!!\n");
pthread_exit(NULL);


}


/*
void *fun(void *arg)
{
	int *pt;
	pt=(int *)arg;
	printf("%d thread :tid %p\n\n",(*pt),pthread_self());
	return NULL;


}
int main()
{
	pthread_t tid[NUM];
	int i,ret[NUM];
	for(i=0;i<NUM;i++)
	{
		ret[i]=pthread_create(&tid[i],NULL,fun,(void *) &i);
		if(ret[i]!=0)
		{
			printf("thread  create failed\n");
			return -1;
		}
		pthread_join(tid[i],NULL);

	}
return 0;

}
*/
