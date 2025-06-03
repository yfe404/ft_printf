/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfeunteu <yfeunteu@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 23:14:45 by yfeunteu          #+#    #+#             */
/*   Updated: 2025/06/03 23:14:45 by yfeunteu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../utils.h"
#include "../parsing.h"
#include "../numbers_utils_print.h"
#include "../numbers_utils_count.h"

int	func_u(unsigned int arg, t_flags flags)
{
	int	len;
	int	delta;

	flags.zero &= !(flags.precision || flags.minus);
	if (flags.dot && (flags.precision > 0))
	{
		flags.zero = 1;
		flags.width = flags.precision;
	}
	len = ft_count_digits_uint(arg);
	delta = flags.width - len;
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
	return (max(flags.width, len));
}

int	func_x(unsigned int arg, t_flags flags)
{
	int	delta;
	int	count;

	count = 0;
	flags.zero &= !(flags.precision || flags.minus);
	if (flags.dot && (flags.precision > 0))
	{
		flags.zero = 1;
		flags.width = flags.precision;
	}
	delta = flags.width - ft_count_digits_hex((unsigned long)arg);
	if ((delta > 0) && !flags.minus && !flags.zero)
		while (delta--)
			ft_putchar_fd(' ', 1);
	if (arg && flags.hash)
	{
		ft_putstr_fd("0x", 1);
		count += 2;
	}
	ft_putnbr_hex((unsigned long)arg, 0, flags.zero * delta);
	if ((delta > 0) && flags.minus && !flags.zero)
		while (delta--)
			ft_putchar_fd(' ', 1);
	count += (max(flags.width, ft_count_digits_hex((unsigned long)arg)));
	return (count);
}

int	func_upper_x(unsigned int arg, t_flags flags)
{
	int	delta;
	int	count;

	count = 0;
	flags.zero &= !(flags.precision || flags.minus);
	if (flags.dot && (flags.precision > 0))
	{
		flags.zero = 1;
		flags.width = flags.precision;
	}
	delta = flags.width - ft_count_digits_hex((unsigned long)arg);
	if ((delta > 0) && !flags.minus && !flags.zero)
		while (delta--)
			ft_putchar_fd(' ', 1);
	if (arg && flags.hash)
	{
		ft_putstr_fd("0X", 1);
		count += 2;
	}
	ft_putnbr_hex((unsigned long)arg, 1, flags.zero * delta);
	if ((delta > 0) && flags.minus && !flags.zero)
		while (delta--)
			ft_putchar_fd(' ', 1);
	count += (max(flags.width, ft_count_digits_hex((unsigned long)arg)));
	return (count);
}
