#include <unistd.h>
#include <stdarg.h>


void	ft_putstr(const char* str)
{
	while (str && *str)
		write(STDOUT_FILENO, str++, 1);
}

int	ft_strlen(char *str)
{
	int count = 0;

	while (str && str[count])
		count ++;
	return (count);
}

int ft_printf(const char * format, ...)
{
	va_list args;
	va_start(args, format);

	// Need to handle: cspdiuxX%
	// c: unsigned char 
	// s: const char *
	// p: void * pointer argument (printed in hexadecimal)
	// d: int (signed decimal notation)
	// i: same as d ? 
	// u: unsigned int argument (unsigned decimal notation)
	// x: unsinged int argument (unsigned hexadecimal lowercase abcdef)
	// X: unsinged int argument (unsigned hexadecimal uppercase ABCDEF)
	// %: used for formatting, in front of a '%', prints % litterally. 
	
	//	int x = va_arg(args, int);
	//

	int count = 0;
	if (format && *format) 
	{
		unsigned char *ptr; // iterate over all the characters of the format string
		ptr = (unsigned char*)format;

		while (*ptr)
		{
			if (*ptr != '%')
			{
				write(STDOUT_FILENO, ptr, 1);
				count ++;
			} 
			else  // Handle format
			{
				if (*(ptr + 1)) 
				{
					if (*(ptr + 1) == 's') // Handle string format
					{
						char *str = va_arg(args, char*);
						int len = 0;
						len = ft_strlen(str);
						ft_putstr(str);
						count += len;
						ptr += len;
					}
				}
			}
			ptr++;
		}
	}

	write(STDOUT_FILENO, "\0", 1);

	va_end(args);
	return (count);
}

