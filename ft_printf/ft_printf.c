#include <unistd.h>
#include <stdarg.h>

#include "libft.h"
#include "parsing.h"

int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}

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

void	ft_putuint(unsigned int nbr, int padding)
{
	while (padding-- > 0)
		ft_putchar_fd('0', 1);
	if (nbr < 10)
	{
		ft_putchar_fd(nbr + '0', 1);
		return;
	}
	if (nbr)
	{
		ft_putuint(nbr / 10, 0);
		ft_putchar_fd((nbr % 10) + '0', 1);
	}

}

void	ft_putnbr_hex(unsigned long nbr, unsigned char upper, int padding)
{
	char *charset = "0123456789abcdef";
	char *charsetU = "0123456789ABCDEF";

	while (padding-- > 0)
		ft_putchar_fd('0', 1);
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
		ft_putnbr_hex(nbr / 16, upper, 0);
		if (upper)
			ft_putchar_fd(charsetU[nbr % 16], 1);
		else
			ft_putchar_fd(charset[nbr % 16], 1);
	}
}

void ft_putnbr_padding(int nb, int padding)
{
	if (nb < 0)
	{
		ft_putchar_fd('-', 1);
	}
	while (padding-- > 0)
		ft_putchar_fd('0', 1);
	if (nb <= -10 || nb >= 10)
	{
		if (nb < 0)
		{
			ft_putnbr_padding(-(nb / 10), 0);
			ft_putchar_fd(-(nb % -10) + '0', 1);
		}
		else
		{
			ft_putnbr_padding(nb / 10, 0);
			ft_putchar_fd((nb % 10) + '0', 1);
		}
	}
	else
	{
		if (nb < 0)
			ft_putchar_fd(-nb + '0', 1);
		else
			ft_putchar_fd(nb + '0', 1);
	}
}


int ft_printf(const char * format, ...)
{
	va_list args;
	va_start(args, format);

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
					int delta = flags.width - 1;
					if ((delta > 0) && !flags.minus)
					{
						while (delta-- && ++count)
							ft_putchar_fd(' ', 1);
					}
					write(STDOUT_FILENO, &arg, 1);
					if ((delta > 0) && flags.minus)
					{
						while (delta-- && ++count)
							ft_putchar_fd(' ', 1);
					}
					count++;
					format++;
				}
				else if (conversion == 's')
				{
					int len = 0;
					char *arg = va_arg(args, char*);

					if (arg == NULL)
					{
						if (flags.width > 6)
						{
							int count = flags.width - 6;
							if (!flags.minus)
							{
								while (count--)
									ft_putchar_fd(' ', 1);
							}
						}
						ft_putstr_fd("(null)", 1);
						if (flags.width > 6)
						{
							int count = flags.width - 6;
							if (flags.minus)
							{
								while (count--)
									ft_putchar_fd(' ', 1);
							}
						}
						count += max(6, flags.width);
					}
					else
					{
						len = ft_strlen(arg);
						int delta = flags.width - len;
						if ((delta > 0) && !flags.minus)
						{
							while (delta-- && ++count)
								ft_putchar_fd(' ', 1);
						}
						if (flags.dot)
						{	count += min(len,flags.precision);
							int iter = min(len, flags.precision);
							int offset = 0;
							while (iter--)
								ft_putchar_fd(arg[offset++], 1);
						}
						else
						{
							ft_putstr_fd(arg, 1);
							count += len;
						}
						if ((delta > 0) && flags.minus)
						{
							while (delta-- && ++count)
								ft_putchar_fd(' ', 1);
						}
						//count += len;
					}
					format += 1;
				}
				else if (conversion == 'p')
				{
					void *arg = va_arg(args, void*);
					if (arg == NULL)
					{
						if (flags.width > 5)
						{
							int count = flags.width - 5;
							if (!flags.minus)
							{
								while (count--)
									ft_putchar_fd(' ', 1);
							}
						}
						ft_putstr_fd("(nil)", 1);
						if (flags.width > 5)
						{
							int count = flags.width - 5;
							if (flags.minus)
							{
								while (count--)
									ft_putchar_fd(' ', 1);
							}
						}
						count += max(5, flags.width);
					}
					else
					{
						int len = ft_count_digits_hex((unsigned long)arg) + 2; 
						int delta = flags.width - len;
						if ((delta > 0) && !flags.minus)
						{
							while (delta-- && ++count)
								ft_putchar_fd(' ', 1);
						}

						write(1, "0x", 2);
						ft_putnbr_hex((unsigned long)arg, 0, 0);
						if ((delta > 0) && flags.minus)
						{
							while (delta-- && ++count)
								ft_putchar_fd(' ', 1);
						}
						
						count += len;
					}
					format += 1;
				}
				else if (conversion == 'd' || conversion == 'i')
				{
					int arg = va_arg(args, int);
					char prefix;
					if (flags.space || flags.plus)
					{
						prefix = flags.plus * '+';
						prefix = prefix + !prefix * ' ';
					}
					flags.zero &= !(flags.dot || flags.minus);
					if (flags.dot)
					{
						if (flags.precision > 0)
						{
							flags.zero = 1;
							flags.width = flags.precision + (arg < 0);
						}
					}

					int len = ft_count_digits_dec(arg) + (flags.plus || flags.space) * (arg >= 0); 
					int delta = flags.width - len;
					if ((delta > 0) && !flags.minus && !flags.zero)
					{
						while (delta--)
							ft_putchar_fd(' ', 1);
					}
					if ((flags.space || flags.plus) && (arg >= 0)) 
						ft_putchar_fd(prefix, 1);
					ft_putnbr_padding(arg, flags.zero * delta);
					if ((delta > 0) && flags.minus && !flags.zero)
					{
						while (delta--)
							ft_putchar_fd(' ', 1);
					}

					count += max(flags.width, len); 
					format += 1;
				}
				else if (conversion == 'u')
				{
					unsigned int arg = va_arg(args, unsigned int);
					flags.zero &= !(flags.precision || flags.minus);
					if (flags.dot)
					{
						if (flags.precision > 0)
						{
							flags.zero = 1;
							flags.width = flags.precision;
						}
					}
					int len = ft_count_digits_uint(arg);
					int delta = flags.width - len;
					if ((delta > 0) && !flags.minus && !flags.zero)
					{
						while (delta--)
							ft_putchar_fd(' ', 1);
					}
					ft_putuint(arg, flags.zero * delta);
					if ((delta > 0) && flags.minus && !flags.zero)
					{
						while (delta--)
							ft_putchar_fd(' ', 1);
					}
					count += max(flags.width, len); 
					//count += len; 
					format += 1;
				}
				else if (conversion == 'x')
				{
					unsigned int arg = va_arg(args, unsigned int);
					flags.zero &= !(flags.precision || flags.minus);
					if (flags.dot)
					{
						if (flags.precision > 0)
						{
							flags.zero = 1;
							flags.width = flags.precision;
						}
					}

					int len = ft_count_digits_hex((unsigned long)arg);
					int delta = flags.width - len;
					if ((delta > 0) && !flags.minus && !flags.zero)
					{
						while (delta--)
							ft_putchar_fd(' ', 1);
					}
					if (arg && flags.hash)
					{
						ft_putstr_fd("0x", 1);
						count += 2;
					}
						
					ft_putnbr_hex((unsigned long)arg, 0, flags.zero * delta);
					if ((delta > 0) && flags.minus && !flags.zero)
					{
						while (delta--)
							ft_putchar_fd(' ', 1);
					}
					count += max(flags.width, len); 
					//count += len;
					format += 1;
				}
				else if (conversion == 'X')
				{
					unsigned int arg = va_arg(args, unsigned int);
					flags.zero &= !(flags.precision || flags.minus);
					if (flags.dot)
					{
						if (flags.precision > 0)
						{
							flags.zero = 1;
							flags.width = flags.precision;
						}
					}

					int len = ft_count_digits_hex((unsigned long)arg);
					int delta = flags.width - len;
					if ((delta > 0) && !flags.minus && !flags.zero)
					{
						while (delta--)
							ft_putchar_fd(' ', 1);
					}
					if (arg && flags.hash)
					{
						ft_putstr_fd("0X", 1);
						count += 2;
					}

					ft_putnbr_hex((unsigned long)arg, 1, flags.zero * delta);
					if ((delta > 0) && flags.minus && !flags.zero)
					{
						while (delta--)
							ft_putchar_fd(' ', 1);
					}
					count += max(flags.width, len); 
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
		}
	}
	write(STDOUT_FILENO, "\0", 1);

	va_end(args);
	return (count);
}

