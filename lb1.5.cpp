#define _CRT_SECURE_NO_WARNINGS
#include "time.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "locale.h"

int main(void)
{
	setlocale(LC_ALL, "Rus");
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	int i;
	struct student {
		char famil[20];
		char name[20], facult[20];
		int Nomzach;
	} stud[3];


	for (i = 0; i < 3; i++)
	{
		printf("Введите фамилию студента\n"); scanf("%20s", stud[i].famil);
	}
	for (i = 0; i < 3; i++)
	{
		printf("Введите имя студента %s\n", stud[i].famil); scanf("%20s", stud[i].name);
	}
	for (i = 0; i < 3; i++)
	{
		printf("Введите название факультета студента %s %s\n", stud[i].famil, stud[i].name); scanf("%20s", stud[i].facult);
	}
	for (i = 0; i < 3; i++)
	{
		printf("Введите номер зачётной книжки студента %s %s\n", stud[i].famil, stud[i].name); scanf("%d", &stud[i].Nomzach);
	}

	for (i = 0; i < 3; i++)
	{
		printf("Cтудент %s %s обучается на факультете %s, номер зачётной книжки %d \n", stud[i].famil, stud[i].name,
			stud[i].facult, stud[i].Nomzach);
	}

	char search_famil[20], search_name[20], search_facult[20];

	printf("\nВведите фамилию студента для поиска: "); scanf("%20s", search_famil);

	printf("Введите имя студента для поиска: ");
	scanf("%20s", search_name);

	printf("Введите факультет студента для поиска: ");
	scanf("%20s", search_facult);

	int found = 0;

	for (i = 0; i < 3; i++) {
		if (strcmp(stud[i].famil, search_famil) == 0 &&
			strcmp(stud[i].name, search_name) == 0 &&
			strcmp(stud[i].facult, search_facult) == 0) {

			printf("\nНайден студент: %s %s, факультет: %s, номер зачётной книжки: %d\n",
				stud[i].famil, stud[i].name, stud[i].facult, stud[i].Nomzach);
			found = 1;
			break;
		}
	}

	if (!found) {
		printf("\nСтудент с указанными параметрами не найден.\n");
	}

	return 0;
}