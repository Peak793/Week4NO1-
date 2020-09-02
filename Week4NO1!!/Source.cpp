#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double average(int *p,int n)
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
	for (int i = 0; i < n - 1; i++)
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
	int* age;
	scanf("%d", &n);
	if (n < 0 || n>50)
	{
		printf("Error");
		return 0;
	}
	age = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		scanf("%d",age+i);
		if (*(age + i) < 0 || *(age+i) >120)
		{
			printf("Error");
			return 0;
		}
	}
	bubblesort(age,n);
	printf("Average : %.2lf\n", average(age, n));
	printf("Range : %d\n", abs(*(age + (n - 1)) - *(age + 0)));
	printf("SD : %.2lf", sd(age, average(age, n),n));
	return 0;
}