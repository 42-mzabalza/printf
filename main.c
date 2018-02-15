
#include <locale.h>
#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>
#include <wchar.h>
#include <unistd.h>

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

int		main()
{

	//printf(“\033[0;31m]”);
	//printf("hola hola");

	ft_printf("{RED} This text is RED!"    "\n");
	ft_printf("hola hola");
	
	return (0);
}