/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfeunteu <yfeunteu@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 23:26:15 by yfeunteu          #+#    #+#             */
/*   Updated: 2025/06/03 23:26:15 by yfeunteu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../utils.h"
#include "../parsing.h"
#include "../numbers_utils_print.h"
#include "../numbers_utils_count.h"

static char	get_prefix(t_flags flags)
{
	char	prefix;

	if (flags.space || flags.plus)
	{
		prefix = flags.plus * '+';
		prefix = prefix + !prefix * ' ';
	}
	return (prefix);
}

int	func_int(int arg, t_flags flags)
{
	char	prefix;
	int		len;
	int		delta;

	prefix = get_prefix(flags);
	flags.zero &= !(flags.dot || flags.minus);
	if (flags.dot && (flags.precision > 0))
	{
		flags.zero = 1;
		flags.width = flags.precision + (arg < 0);
	}
	len = ft_count_digits_dec(arg) + (flags.plus || flags.space) * (arg >= 0);
	delta = flags.width - len;
	if ((delta > 0) && !flags.minus && !flags.zero)
		while (delta--)
			ft_putchar_fd(' ', 1);
	if ((flags.space || flags.plus) && (arg >= 0))
		ft_putchar_fd(prefix, 1);
	ft_putnbr_padding(arg, flags.zero * delta);
	if ((delta > 0) && flags.minus && !flags.zero)
		while (delta--)
			ft_putchar_fd(' ', 1);
	return (max(flags.width, len));
}
