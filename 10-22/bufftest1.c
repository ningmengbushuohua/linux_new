#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int globa=4;
int main (void)
{
	pid_t pid;
	int vari=5;
	printf("before \n");
	if((pid==fork())<0)
	{
	printf("fork error \n");
	exit(0);
	}
	else if(pid ==0)
	{
	globa++;
	vari--;
	printf("childred changed \n");
	printf("child:globa =%d vari =%d\n",globa,vari);
	}
	else 
	printf("parent did not changed\n");
	printf("parent:globa =%d vari =%d\n",globa,vari);
	exit(0);

}
