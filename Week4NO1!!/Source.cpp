#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double average(int *p,int n)	// <--- Function
{
	double sum=0, av;
	for (int i = 0; i < n; i++)
	{
		sum += *(p + i);
	}
	av = sum / n;
	return av;
}			
void bubblesort(int *p,int n)		
{	
	for (int i = 0; i < n - 1; i++)				// <--- Nested Loop
	{
		for (int j = 0; j < n - 1 - i;j++)	
		{
			if (*(p + j) > * (p + j + 1))
			{
				int temp = *(p + j);
				*(p + j) = *(p + j + 1);
				*(p + j+1) = temp;
			}
		}
	}
}
double sd(int *p,double x,int n)
{
	double sigma = 0,sd,sum=0;
	for (int i = 0; i < n; i++)
	{
		sum += pow((*(p + i) - x), 2);
	}
	sd = sqrt((sum / (n-1)));
	return sd;
}
int main()
{
	int n;
	int* info;			//Pointer
	scanf("%d", &n);
	if (n < 2 || n>100)					//Expression and or
	{
		printf("Error");
		return 0;
	}
	info = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		scanf("%d",info+i);
		if (*(info + i) < 0 || *(info+i) >5000)    //Expression and or
		{
			printf("Error");
			return 0;
		}
	}
	bubblesort(info,n);
	printf("Average : %.2lf\n", average(info, n));
	printf("Range : %d\n", abs(*(info + (n - 1)) - *(info + 0)));
	printf("SD : %.2lf", sd(info, average(info, n),n));
	return 0;
}