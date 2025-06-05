/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfeunteu <yfeunteu@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 23:26:15 by yfeunteu          #+#    #+#             */
/*   Updated: 2025/06/05 11:26:49 by yfeunteu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../utils.h"
#include "../parsing.h"
#include "../numbers_utils_print.h"
#include "../numbers_utils_count.h"
#include "common.h"

static int	get_sign(int number, t_flags flags, t_format *format)
{
	if (number < 0)
	{
		format->sign_chr = '-';
		return (1);
	}
	if (flags.plus)
	{
		format->sign_chr = '+';
		return (1);
	}
	if (flags.space)
	{
		format->sign_chr = ' ';
		return (1);
	}
	return (0);
}

static int	zeros(int number, t_flags flags, t_format *format)
{
	int	digits_count;

	if (!flags.dot)
		return (0);
	digits_count = ft_count_digits_dec(number);
	format->n_zeros = max(0, flags.precision - digits_count);
	return (format->n_zeros);
}

static int	padding(int num, t_flags flags, t_format *format)
{
	int	pad_width;

	pad_width = max(0, flags.width - (format->sign_chr != 0) \
	- format->n_zeros - ft_count_digits_dec(num));
	if (flags.minus)
		format->n_pad_right = pad_width;
	else
		format->n_pad_left = pad_width;
	if (flags.zero && !(flags.dot || flags.minus))
		format->pad_chr = '0';
	else
		format->pad_chr = ' ';
	return (pad_width);
}

int	func_int(int arg, t_flags flags)
{
	int			count;
	t_format	format;

	format = init_format();
	if (arg == 0 && flags.precision == 0 && flags.dot)
	{
		count = flags.width;
		while (flags.width--)
			ft_putchar_fd(' ', 1);
		return (count);
	}
	count = zeros(arg, flags, &format) + get_sign(arg, flags, &format);
	count += padding(arg, flags, &format) + ft_count_digits_dec(arg);
	while (format.pad_chr == ' ' && format.n_pad_left--)
		ft_putchar_fd(' ', 1);
	if (format.sign_chr)
		ft_putchar_fd(format.sign_chr, 1);
	while (format.pad_chr == '0' && format.n_pad_left--)
		ft_putchar_fd('0', 1);
	while (format.n_zeros--)
		ft_putchar_fd('0', 1);
	ft_putnbr_nosign_fd(arg, 1);
	while (format.pad_chr == ' ' && format.n_pad_right--)
		ft_putchar_fd(' ', 1);
	return (count);
}
