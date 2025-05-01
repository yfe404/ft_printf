#include <unistd.h>
#include <stdarg.h>

#include "libft.h"
#include "parsing.h"

int ft_count_digits_hex(unsigned long nb)
{
	if (nb < 16)	
		return 1;
	return 1 + ft_count_digits_hex(nb / 16);

}

int ft_count_digits_dec(int nb)
{
	if (nb == 0)
		return 1;
	if (nb <= -10)
		return 2 + ft_count_digits_dec(-(nb / 10));
	if (nb < 0)
		return 2;
	if (nb < 10)
		return 1;
	return 1 + ft_count_digits_dec(nb / 10);
}

int	ft_count_digits_uint(unsigned int nbr)
{
	if (nbr < 10)	
		return 1;
	return 1 + ft_count_digits_uint(nbr / 10);
}

void	ft_putuint(unsigned int nbr)
{
	if (nbr < 10)
	{
		ft_putchar_fd(nbr + '0', 1);
		return;
	}
	if (nbr)
	{
		ft_putuint(nbr / 10);
		ft_putchar_fd((nbr % 10) + '0', 1);
	}

}

void	ft_putnbr_hex(unsigned long nbr, unsigned char upper)
{
	char *charset = "0123456789abcdef";
	char *charsetU = "0123456789ABCDEF";

	if (nbr < 16)
	{
		if (upper)	
			ft_putchar_fd(charsetU[nbr], 1);
		else
			ft_putchar_fd(charset[nbr], 1);
		return;
	}
	if (nbr)
	{
		ft_putnbr_hex(nbr / 16, upper);
		if (upper)
			ft_putchar_fd(charsetU[nbr % 16], 1);
		else
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
	// x: unsigned int argument (unsigned hexadecimal lowercase abcdef)
	// X: unsigned int argument (unsigned hexadecimal uppercase ABCDEF)
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
				if (conversion == 'c')
				{
					char arg = va_arg(args, int);
					write(STDOUT_FILENO, &arg, 1);
					count++;
					format++;
				}
				else if (conversion == 's')
				{
					int len = 0;
					char *arg = va_arg(args, char*);

					if (arg == NULL)
					{
						ft_putstr_fd("(null)", 1);
						count += 6;
					}
					else
					{
						len = ft_strlen(arg);
						ft_putstr_fd(arg, 1);
						count += len;
					}
					format += 1;
				}
				else if (conversion == 'p')
				{
					void *arg = va_arg(args, void*);
					if (arg == NULL)
					{
						ft_putstr_fd("(nil)", 1);
						count += 5;
					}
					else
					{
						write(1, "0x", 2);
						ft_putnbr_hex((unsigned long)arg, 0);
						count += 2;
						count += ft_count_digits_hex((unsigned long)arg);
					}
					format += 1;
				}
				else if (conversion == 'd')
				{
					int arg = va_arg(args, int);
					if (flags.space)
					{
						if (arg >= 0)
						{
							count++;
							ft_putchar_fd(' ', 1);
						}
					}
					ft_putnbr_fd(arg, 1);
					count += ft_count_digits_dec(arg);
					format += 1;
				}
				else if (conversion == 'i')
				{
					int arg = va_arg(args, int);
					if (flags.space)
					{
						if (arg >= 0)
						{
							count++;
							ft_putchar_fd(' ', 1);
						}
					}
					ft_putnbr_fd(arg, 1);
					count += ft_count_digits_dec(arg);
					format += 1;
				}
				else if (conversion == 'u')
				{
					unsigned int arg = va_arg(args, unsigned int);
					ft_putuint(arg);
					count += ft_count_digits_uint(arg);
					format += 1;
				}
				else if (conversion == 'x')
				{
					unsigned int arg = va_arg(args, unsigned int);
					ft_putnbr_hex((unsigned long)arg, 0);
					count += ft_count_digits_hex((unsigned long)arg);
					format += 1;
				}
				else if (conversion == 'X')
				{
					unsigned int arg = va_arg(args, unsigned int);
					ft_putnbr_hex((unsigned long)arg, 1);
					count += ft_count_digits_hex((unsigned long)arg);
					format += 1;
				}
				else if (conversion == '%')
				{
					ft_putchar_fd('%', 1);
					count += 1;
					format += 1;
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

