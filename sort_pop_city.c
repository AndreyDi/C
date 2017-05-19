#include <stdio.h>
#define SIZE 9
void SortArPrintMaxtoMin(const char **string, const int num[], int n);
/*Функция сортировки и печати 2-х массивов
последовательно от большего значения к меньшему*/
int main(void)
{
	const int pop[SIZE] = 
	{
		12330126, 8405837, 8538689, 1974800,
		2928193,  1744351, 3490105, 13370198,
		7182724
	};
	const char *cities[] = 
	{ 
		"Moscow", "New-York", "London", "Minsk",
		"Kiev",   "Warsaw",   "Berlin", "Tokio",
		"Hong-Kong"
	};

	printf("\n  Сity      Population\n");
	SortArPrintMaxtoMin(cities, pop, SIZE);

	return 0;
}

void SortArPrintMaxtoMin(const char **string, const int num[], int n)
{
	int gmax = 0;   // наибольшее невыведенное значение 
	int max = 0;    // наибольшее невыведенное значение меньше gmax
	int gi = 0;     // индекс наибольшего невыведенное


	for (int i = 0; i < n; i++)
	{
		if(gmax < num[i])
		{
			gi = i;
			gmax = num[i];
		}
	}
	printf(" %-9s   %d\n", string[gi], num[gi]);	
	for (int j = 1; j < n; j++, max = 0)     // счетчик для оставшихся 8 эелементов
	{   // если в 45 строке for (int i = 0, max = 0; i < n; i++) код работает некорректно.
		for (int i = 0; i < n; i++)
		{ 
			if (num[i] <  gmax)     // поиск всех чисел меньше gmax
			{ 
				if (max < num[i])   // отбор наибольшего числа меньше gmax
				{
					gi = i;
					max = num[i];
				}		
					
			}
		}
		gmax = max;									
		printf(" %-9s   %d\n", string[gi], num[gi]);		
	}
	printf("\n");	
}