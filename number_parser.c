#include "number_parser.h"

int	f_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int 	f_power(int base, int power)
{
	if (power < 1)
		return (1);
	else
		return (f_power(base, power - 1) * base);
}

int	is_there_zero(char *str, int index)
{
	int	i;

	i = 3;
	while (index >= 0 && i > 0)
	{
		if (str[index] != '0')
			return (1);
		index--;
		i--;
	}
	return (0);
}
