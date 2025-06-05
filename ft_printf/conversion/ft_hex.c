/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfeunteu <yfeunteu@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:21:06 by yfeunteu          #+#    #+#             */
/*   Updated: 2025/06/05 11:24:00 by yfeunteu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../utils.h"
#include "../parsing.h"
#include "../numbers_utils_print.h"
#include "../numbers_utils_count.h"
#include "common.h"

static int	zeros(int number, t_flags flags, t_format *format)
{
	int	digits_count;

	if (!flags.dot)
		return (0);
	digits_count = ft_count_digits_hex((unsigned int)number);
	format->n_zeros = max(0, flags.precision - digits_count);
	return (format->n_zeros);
}

static int	padding(int num, t_flags flags, t_format *format)
{
	int	pad_width;

	pad_width = max(0, flags.width - format->n_zeros \
	- ft_count_digits_hex((unsigned int)num) - 2 * flags.hash);
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

int	func_x(unsigned int arg, t_flags flags)
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
	count = zeros(arg, flags, &format) + padding(arg, flags, &format);
	count += ft_count_digits_hex((unsigned long)arg) + 2 * (arg && flags.hash);
	while (format.pad_chr == ' ' && format.n_pad_left--)
		ft_putchar_fd(' ', 1);
	if (arg && flags.hash)
		ft_putstr_fd("0x", 1);
	while (format.pad_chr == '0' && format.n_pad_left--)
		ft_putchar_fd('0', 1);
	while (format.n_zeros--)
		ft_putchar_fd('0', 1);
	ft_putnbr_hex(arg, 0, 0);
	while (format.pad_chr == ' ' && format.n_pad_right--)
		ft_putchar_fd(' ', 1);
	return (count);
}

int	func_upper_x(unsigned int arg, t_flags flags)
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
	count = zeros(arg, flags, &format) + padding(arg, flags, &format);
	count += ft_count_digits_hex((unsigned long)arg) + 2 * (arg && flags.hash);
	while (format.pad_chr == ' ' && format.n_pad_left--)
		ft_putchar_fd(' ', 1);
	if (arg && flags.hash)
		ft_putstr_fd("0X", 1);
	while (format.pad_chr == '0' && format.n_pad_left--)
		ft_putchar_fd('0', 1);
	while (format.n_zeros--)
		ft_putchar_fd('0', 1);
	ft_putnbr_hex(arg, 1, 0);
	while (format.pad_chr == ' ' && format.n_pad_right--)
		ft_putchar_fd(' ', 1);
	return (count);
}
