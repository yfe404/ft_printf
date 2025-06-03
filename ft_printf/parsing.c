/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfeunteu <yfeunteu@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 01:36:45 by yfeunteu          #+#    #+#             */
/*   Updated: 2025/06/04 01:36:47 by yfeunteu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_flags	init_flags(void)
{
	t_flags	flags;

	flags.minus = 0;
	flags.zero = 0;
	flags.hash = 0;
	flags.plus = 0;
	flags.space = 0;
	flags.width = 0;
	flags.precision = 0;
	flags.dot = 0;
	return (flags);
}

int	is_flag(char c)
{
	return (c == '-' || c == '0' || c == '#' || c == '+' || c == ' ');
}

const char	*parse_flags(const char *format, t_flags *flags)
{
	while (is_flag(*format))
	{
		if (*format == '-')
			flags->minus = 1;
		else if (*format == '0')
			flags->zero = 1;
		else if (*format == '#')
			flags->hash = 1;
		else if (*format == '+')
			flags->plus = 1;
		else if (*format == ' ')
			flags->space = 1;
		format++;
	}
	return (format);
}

const char	*parse_width(const char *format, t_flags *flags)
{
	while (*format >= '0' && *format <= '9')
	{
		flags->width = flags->width * 10 + (*format - '0');
		format++;
	}
	return (format);
}

const char	*parse_precision(const char *format, t_flags *flags)
{
	if (*format == '.')
	{
		flags->dot = 1;
		format++;
		flags->precision = 0;
		while (*format >= '0' && *format <= '9')
		{
			flags->precision = flags->precision * 10 + (*format - '0');
			format++;
		}
	}
	return (format);
}
