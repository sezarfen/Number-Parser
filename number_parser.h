#ifndef NUMBER_PARSER_H
# define NUMBER_PARSER_H

# include <stdio.h>
# include <stdlib.h>

int	f_strlen(char *str);
int	f_power(int base, int power);
int	is_there_zero(char *str, int index);
int	*number_parser_turkish(char *str);
int	*number_parser_english(char *str);
int	*number_parser_deutsch(char *str);

#endif
