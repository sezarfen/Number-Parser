#include "number_parser.h"

int	*number_parser_turkish(char *str)
{
	int	*numbers;
	int	i;
	int	k; 							// index number for numbers array
	int	len;		 					// we need len in order to detect the total length

	numbers = (int *)malloc(sizeof(int) * f_strlen(str) * 2);
	len = f_strlen(str);
	i = 0;
	k = 0;	

	while (str[i])
	{
		if ((len - i) % 3 == 0)
		{
			if (str[i] != '1')				 // if number not starts with 1 at that index it is okay to write that number.
				numbers[k++] = str[i] - 48;
			if (str[i] != '0')
				numbers[k++] = 100;
		}
		else if ((len - i) % 3 == 2)
		{
			numbers[k++] = (str[i] - 48) * 10;
		}
		else if ((len - i) % 3 == 1)
		{
			if ((str[i] != '1' || (i != 0)) || (str[i] == '1' && i == 0) && !(len == 4 && str[0] == '1')) // last case special for 1000(bin)
				numbers[k++] = str[i] - 48;
			if ((len - i) > 3 && is_there_zero(str, i) == 1)  // If there are no nonzero digit in 3 element queue, don't have to write 10^power
				numbers[k++] = f_power(10, len - i - 1);
		}
		i++;
	}
	numbers[k] = 1453; 		 				// in order to indicate endpoint
	return (numbers);
}

/* TESTING
int main(int ac, char **av)
{
	int *numbers = number_parser_turkish(av[1]);
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
