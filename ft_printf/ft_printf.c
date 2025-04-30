#include <unistd.h>
#include <stdarg.h>

#include "libft.h"
#include "parsing.h"

int ft_count_digits_hex(unsigned long nb)
{
	if (nb == 0)	
		return 1;
	return 1 + ft_count_digits_hex(nb / 16);

}

void	ft_putnbr_hex(unsigned long nbr)
{
	char *charset = "0123456789abcdef";

	write(1, "0x", 2);
	if (nbr == 0)
		ft_putchar_fd('0', 1);
	if (nbr)
	{
		ft_putnbr_hex(nbr / 16);
		ft_putchar_fd(charset[nbr % 16], 1);
	}
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
		while (*format)
		{
			if (*format == '%')
			{
				format++;
				if (!format)
					break;
   				t_flags flags = init_flags();
    			format = parse_flags(format, &flags);
			    format = parse_width(format, &flags);
    			format = parse_precision(format, &flags);

				char conversion = *format;
				if (conversion == '%')
				{
					write(STDOUT_FILENO, format, 1);
				}
				else if (conversion == 'c')
				{
					char arg = va_arg(args, int);
					write(STDOUT_FILENO, &arg, 1);
					count++;
					format++;
				}
				else if (conversion == 's')
				{
					char *arg = va_arg(args, char*);
					int len = 0;
					len = ft_strlen(arg);
					ft_putstr_fd(arg, 1);
					count += len;
					format += 1;
				}
				else if (conversion == 'p')
				{
					void *arg = va_arg(args, void*);
					ft_putnbr_hex((unsigned long)arg);
					count += ft_count_digits_hex((unsigned long)arg);
					format += sizeof(void*);
				}
			}
			else
			{
				write(STDOUT_FILENO, format, 1);
				count++;
				format++;
			} 
			/*else  // Handle format
			{
				if (*(ptr + 1)) 
				{
					if (*(ptr + 1) == 's') // Handle string format
					{
						char *str = va_arg(args, char*);
						int len = 0;
						len = ft_strlen(str);
						ft_putstr_fd(str, 1);
						count += len;
						ptr += len;
					}
					else if (*(ptr + 1) == 'd') // Handle int format
					{
						int arg = va_arg(args, int);
						(void)arg;
						arg += 0; // just to bp with gdp
					}

				}
			} */
		}
	}

	write(STDOUT_FILENO, "\0", 1);

	va_end(args);
	return (count);
}

