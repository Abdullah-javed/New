#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main()
{
	int cpid1,cpid2,cpid3,cpid4;
	int array[100];
	int sum=0;
	for(int i=0;i<100;i++)
	{
		cpid1=fork();
		if(cpid1==0 && i>=0 &&i<25)
			sum+=array[i];
		else
			printf("Error: could not find result \n");
	
		cpid2=fork();
		if(cpid2==0 && i>=25 && i<50)
			sum+=array[i];
		else
			printf("Error: could not find result \n");
	
		cpid3=fork();
		if(cpid3==0 && i>=50 && i<75)
			sum+=array[i];
		else
			printf("Error: could not find result \n");

		cpid4=fork();
		if(cpid4==0 && i>=75 && i<=100)
			sum+=array[i];
		else
			printf("Error: could not find result \n");
	}
	printf("Total overall sum of array is:");
	printf("%d",sum);
	
	return 0;
}