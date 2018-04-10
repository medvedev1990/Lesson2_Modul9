#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>
#include"Header.h"

void main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int n, quit;
	do
	{
		printf("������� ����� �������: ");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
		{
			/*1.������ ������������ �����. ������� ������ �� ���� �����, ���� �� ���������� ����� 10. ��������� ����� ������������� ��������� �������*/
			int *mass = NULL;
			mass = (int*)calloc(1, sizeof(int));
			if (mass == NULL)
			{
				printf("No memmory");
				exit(0);
			}
			else
			{
				int i = 0, a;
				do
				{
					if (scanf("%d", &a) == 0)
						break;
					else
					{
						if (a == 10)
							break;
						else
						{
							*(mass + i) = a;
							i++;
							mass = (int*)realloc(mass, sizeof(int)*(i + 1));
						}
					}
				} while (true);

				print_One_Mass(mass, &i);
				otr_Summ(mass, &i);
			}
		}
		break;
		case 2:
		{
			/*2.������ � StringGrid ������ �� 10 ����� �����. ������� ��� ����� ������� � �� ������������� � ������������� ��������� ��������� �������. ���������� ����� ��������� ������� �������.*/
			int *mass = NULL;
			int row = 10;
			mass = (int*)calloc(row, sizeof(int));
			if (mass == NULL)
			{

				printf("������ �� ��������!");
				exit(0);
			}
			else
			{
				ZappMass(mass, &row);
				print_One_Mass(mass, &row);
				int *massPol = NULL;
				massPol = (int*)calloc(1, sizeof(int));
				int *massOtr = NULL;
				massOtr = (int*)calloc(1, sizeof(int));
				if (massPol == NULL)
				{
					printf("������ �� ��������!");
					exit(0);
				}
				if (massOtr == NULL)
				{
					printf("������ �� ��������!");
					exit(0);
				}
				else
				{
					int i;
					int chek = 0;
					int chek2 = 0;
					int summ = 0;
					int summ2 = 0;
					for (i = 0;i < row;i++)
					{
						if (*(mass + i) >= 0)
						{
							summ += *(mass + i);
							*(massPol + chek) = *(mass + i);
							chek++;
							massPol = (int*)realloc(massPol, sizeof(int)*(chek + 1));
						}
						else
						{
							summ2 += *(mass + i);
							*(massOtr + chek2) = *(mass + i);
							chek2++;
							massOtr = (int*)realloc(massOtr, sizeof(int)*(chek2 + 1));
						}
					}
					print_One_Mass(massPol, &chek);
					print_One_Mass(massOtr, &chek2);
					printf("����� ������������� ��������� = %d \n ����� ������������� ��������� = %d\n", summ, summ2);
				}
			}
		}
		break;
		case 3:
		{
			/*3.������ ������ �� 9 ������������ �����. ������� ����� ������ �� ��������� ���������, ������� �� ������ ������ 10. ��������� ������� �������������� ��������� ������ �������*/
			int *mass = NULL;
			int row = 9;
			mass = (int*)calloc(row, sizeof(int));
			if (mass == NULL)
			{

				printf("������ �� ��������!");
				exit(0);
			}
			else
			{
				ZappMass(mass, &row);
				print_One_Mass(mass, &row);
				int *mass10 = NULL;
				mass10 = (int*)calloc(1, sizeof(int));
				if (mass10 == NULL)
				{
					printf("������ �� ��������!");
					exit(0);
				}
				else
				{
					int i;
					int chek = 0;
					float summ = 0;
					for (i = 0;i < row;i++)
					{
						if (*(mass + i) < 0)
							*(mass + i) *= -1;
						if (*(mass + i) > 10)
						{
							*(mass10 + chek) = *(mass + i);
							summ += *(mass10 + chek);
							chek++;
							mass10 = (int*)realloc(mass10, sizeof(int)*(chek + 1));
						}

					}
					print_One_Mass(mass10, &chek);
					printf("������� �������������� = %2.2f\n", summ / chek);
				}
			}
		}
		break;
		case 4:
		{
			/*4.������ ������������ �����. ������� ������ �� ������������� �����. ����������, �������� �� ������ ������������� �� �����������.*/
			int i = 0, a;
			int *mass = NULL;
			mass = (int*)calloc(1, sizeof(int));
			if (mass == NULL)
			{
				printf("No memmory");
				exit(0);
			}
			else
			{
				do
				{
					if (scanf("%d", &a) == 0)
						break;
					else
					{
						*(mass + i) = a;
						i++;
						mass = (int*)realloc(mass, sizeof(int)*(i + 1));
					}
				} while (true);
				poryadok(mass, &i);
			}
		}
		break;
		case 5:
		{
			/*5.������ ����� �����. ������� ������ �� ���� ����� �� ������� �������������� �����. ����������, �������� �� ������ ������������� �� ��������.*/
			int i = 0, a;
			int *mass = NULL;
			mass = (int*)calloc(1, sizeof(int));
			if (mass == NULL)
			{
				printf("No memmory");
				exit(0);
			}
			else
			{
				do
				{
					scanf("%d", &a);
					if (a < 0)
						break;
					else
					{
						*(mass + i) = a;
						i++;
						mass = (int*)realloc(mass, sizeof(int)*(i + 1));
					}
				} while (true);
				print_One_Mass(mass, &i);
				poryadok_Ubivanie(mass, &i);
			}
		}
		break;
		case 6:
		{
			/*6.������ ������ �� 15 ������������ �����. ������� ����� ������ �� ��������� ���������,
			� ������� �� �������� ��������, ���������� � ���������� (-3,7). ���������� ������������ ������������� ��������� ������ �������*/
			int i = 0, a=0;
			int *mass = NULL;
			int *mass2 = NULL;
			int row = 15;
			mass = (int*)calloc(row, sizeof(int));
			if (mass == NULL)
			{
				printf("No memmory");
				exit(0);
			}
			else
			{
				ZappMass(mass, &row);
				mass2 = (int*)calloc(1, sizeof(int));
				if (mass2 == NULL)
				{
					printf("No memmory");
					exit(0);
				}
				else
				{
					for (i = 0;i < row;i++)
					{
						if (*(mass + i) < -3 || *(mass + i) > 7)
						{
							*(mass2 + a) = *(mass + i);
							a++;
							mass2 = (int*)realloc(mass2, sizeof(int)*(a + 1));
						}	
					}
				}
			}
			print_One_Mass(mass, &row);
			poryadok_Ubivanie(mass, &i);
			print_One_Mass(mass2, &a);
		}
		break;
		case 7:
		{
			/*7.������ ����� �����. ������� ������ �� �����, ������� �� ������� �� 5. ���������� ����������� ������� �������.*/
			int i = 0, a;
			int *mass = NULL;
			mass = (int*)calloc(1, sizeof(int));
			if (mass == NULL)
			{
				printf("No memmory");
				exit(0);
			}
			else
			{
				do
				{
					if (scanf("%d", &a) == 0)
						break;
					else
					{
						if (a % 5 == 0)
						{
							*(mass + i) = a;
							i++;
							mass = (int*)realloc(mass, sizeof(int)*(i + 1));
						}
					}
				} while (true);
				print_One_Mass(mass, &i);
				min(mass, &i);
			}
		}
		break;
		case 8:
		{
			/*8.������ ������������ �����. ������� ������ �� ���� �����, ���� �� ���������� ����� 33. ���������� ������������ ������� �������*/
			int i = 0, a;
			int *mass = NULL;
			mass = (int*)calloc(1, sizeof(int));
			if (mass == NULL)
			{
				printf("No memmory");
				exit(0);
			}
			else
			{
				do
				{
					scanf("%d", &a);
					if (a == 33)
						break;
					else
					{
						*(mass + i) = a;
						i++;
						mass = (int*)realloc(mass, sizeof(int)*(i + 1));
					}
				} while (true);
				print_One_Mass(mass, &i);
				max(mass, &i);
			}
		}
		break;
		default:printf("��� ������ �������\n");
			break;
		}
		printf("���������� 1-�� 2-���: ");
		scanf("%d", &quit);

	} while (quit == 1);
}