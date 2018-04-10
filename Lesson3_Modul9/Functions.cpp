#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>
#include"Header.h"
int i, j;

void print_One_Mass(int *mass, int*row)
{
	for (i = 0;i < *row;i++)
	{
		printf("%d\t", *(mass + i));
	}
	printf("\n");
}
void otr_Summ(int *mass, int *row)
{
	int summ = 0;
	for (i = 0;i < *row;i++)
	{
		if (*(mass + i) < 0)
		{
			summ += *(mass + i);
		}
	}
	printf("сумма отрицательных элементов = %d\n", summ);
}
void ZappMass(int *mass, int *row)
{
	for (i = 0;i < *row;i++)
		*(mass + i) = -5 + rand() % 20;
}
void poryadok(int *mass, int *row)
{
	int chek = 0;
	for (i = 1;i < *row;i++)
	{
		if (*(mass + (i - 1)) < *(mass + i))
			chek++;

	}
 	if ((chek == *row-1))
		printf("массив является упорядоченным по возростанию\n");
}
void poryadok_Ubivanie(int *mass, int *row)
{
	int chek2 = 0;
	for (i = 1;i < *row;i++)
	{
		if (*(mass + (i - 1)) > *(mass + i))
			chek2++;	
	}
	if ((chek2 == *row - 1))
		printf("массив является упорядоченным по убыванию\n");
}
void min(int *mass, int *row)
{
	int min = *mass;
	for (i = 0;i < *row;i++)
	{
		if (min > *(mass + i))
			min = *(mass + i);
	}
	printf("min Element = %d\n", min);
}
void max(int *mass, int *row)
{
	int max = *mass;
	for (i = 0;i < *row;i++)
	{
		if (max < *(mass + i))
			max = *(mass + i);
	}
	printf("max Element = %d\n", max);
}