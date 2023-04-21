#include <stdio.h>
#include <stdlib.h>
#include "number_parser.h"

int	*number_parser_deutsch(char *str)
{
	int	*numbers;
	int	i;
	int	k;
	int	len;

	len = f_strlen(str);
	numbers = (int *) malloc (sizeof(int) * len * 2);
	i = 0;
	k = 0;
	
	while (str[i])
	{
		if ((len - i) % 3 == 0)
		{
			numbers[k++] = str[i] - 48;
			if (str[i] != '0')
				numbers[k++] = 100;
		}
		else if ((len - i) % 3 == 2)
		{	
			if (str[i] == '1')                            // same case for 10-20 numbers
			{ 
				numbers[k] = (str[i++] - 48) * 10;
				numbers[k++] += str[i] - 48;
			}
			else
			{	
				numbers[k++] = str[i++ + 1] - 48;
				numbers[k++] = (str[i - 1] - 48) * 10;
			}	
		}
		if ((len - i) % 3 == 1 && (len - i) > 3 && is_there_zero(str, i) == 1)   // differs from English, different approach for indicating 10^power numbers, 
		{									// no need specifically calling power function again in 10-20 numbers.
			numbers[k++] = f_power(10, len - i - 1);			
		}
		i++;
	}
	numbers[k] = 1453;
	return (numbers);
}

/* TESTING
int main(int ac, char **av)
{
	int	*numbers = number_parser_deutsch(av[1]);
	int	i;

	i = 0;
	while (numbers[i] != 1453)
	{
		printf("[%d] -> %d\n", i, numbers[i]);
		i++;
	}
	return (0);
}	
*/
