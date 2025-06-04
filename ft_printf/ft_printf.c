/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfeunteu <yfeunteu@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 01:10:17 by yfeunteu          #+#    #+#             */
/*   Updated: 2025/06/04 13:23:07 by yfeunteu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

#include "libft.h"
#include "utils.h"
#include "parsing.h"
#include "numbers_utils_print.h"
#include "numbers_utils_count.h"
#include "conversion/conversion.h"

static int	__match_one_of(char c, char *charset)
{
	while (*charset)
		if (c == *charset++)
			return (1);
	return (0);
}

static int	__conversion(char conv, va_list args, t_flags flags, int count)
{
	if (conv == 'u')
		return (count + func_u(va_arg(args, unsigned int), flags));
	else if (conv == 'x')
		return (count + func_x(va_arg(args, unsigned int), flags));
	else if (conv == 'X')
		return (count + func_upper_x(va_arg(args, unsigned int), flags));
	else if (conv == 'c')
		return (func_c(va_arg(args, int), flags, count));
	else if (conv == 's')
		return (func_s(va_arg(args, char *), flags, count));
	else if (conv == 'p')
		return (func_ptr(va_arg(args, void *), flags, count));
	else if (conv == 'd' || conv == 'i')
		return (count + func_int(va_arg(args, int), flags));
	else if (conv == '%')
	{
		ft_putchar_fd('%', 1);
		return (count + 1);
	}
	return (count);
}

static int	__conv_handler(const char **format, va_list args, int count)
{
	t_flags	flags;

	flags = init_flags();
	*format = parse_flags(*format, &flags);
	*format = parse_width(*format, &flags);
	*format = parse_precision(*format, &flags);
	count = __conversion(*(*format), args, flags, count);
	if (__match_one_of(*(*format), "uxXcspdi%"))
		(*format)++;
	return (count);
}

static int	__printc(char c, int count)
{
	write(STDOUT_FILENO, &c, 1);
	return (count + 1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = 0;
	if (format && *format)
	{
		while (*format)
		{
			if (*format == '%')
			{
				format++;
				if (!format)
					break ;
				count = __conv_handler(&format, args, count);
			}
			else
				count = __printc(*format++, count);
		}
	}
	write(STDOUT_FILENO, "\0", 1);
	va_end(args);
	return (count);
}
