#include "number_parser.h"

int	*number_parser(char *str)
{
	int	len;
	int	*numbers;
	int	i;
	int	k; 								// index for numbers array

	len = f_strlen(str);
	numbers = (int *)malloc((len * 2) * sizeof(int));
	i = 0;
	k = 0;									

	while (str[i])
	{
		if ((len - i) % 3 == 0)						// (len - i) current index, (counting numbers, 1,2,3...) (starts from beginning)
		{
			numbers[k++] = str[i] - 48;
			if (str[i] != '0')         		           // If there are 3 digits, there must be 100 (instead of starting with 0)
				numbers[k++] = 100;
		}
		else if ((len - i) % 3 == 2)
		{
			if (str[i] == '1')                                 // indicates special cases for numbers between 10-20
			{
				numbers[k++] = str[++i] - 48 + 10;             
			 	if ((len - i) > 3)
					numbers[k++] = f_power(10, len - i - 1);     // In order to indicate 10^power number , when dealing with 10-20 numbers
			}
			else
				numbers[k++] = (str[i] - 48) * 10;
		}
		else if ((len - i) % 3 == 1)
		{
			numbers[k++] = str[i] - 48;
			if ((len - i) > 3 && is_there_zero(str, i) == 1) 		// indicating nonzero digits in 3 element queue
				numbers[k++] = f_power(10, len - i - 1);
		}
		i++;
	}
	numbers[k] = 1453;
	return (numbers);
}


/* 	TESTING
int 	main(int ac, char **av)
{
	int *numbers = number_parser(av[1]);	
	int	i = 0;
	
	while (numbers[i] != 1453)
	{
		if (numbers[i] != 0)
			printf("[%d] -> %d\n", i, numbers[i]);
		i++;
	}
	return (0);
}
*/
