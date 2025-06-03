/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfeunteu <yfeunteu@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 00:06:31 by yfeunteu          #+#    #+#             */
/*   Updated: 2025/06/04 00:07:16 by yfeunteu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "../utils.h"
#include "../parsing.h"
#include "../numbers_utils_print.h"
#include "../numbers_utils_count.h"

int	func_c(char arg, t_flags flags, int count)
{
	int	delta;

	delta = flags.width - 1;
	if ((delta > 0) && !flags.minus)
		while (delta-- && ++count)
			ft_putchar_fd(' ', 1);
	write(STDOUT_FILENO, &arg, 1);
	if ((delta > 0) && flags.minus)
		while (delta-- && ++count)
			ft_putchar_fd(' ', 1);
	return (++count);
}

static int	__func_s_null(t_flags flags, int count)
{
	if (flags.width > 6)
	{
		count = flags.width - 6;
		if (!flags.minus)
			while (count--)
				ft_putchar_fd(' ', 1);
	}
	ft_putstr_fd("(null)", 1);
	if (flags.width > 6)
	{
		count = flags.width - 6;
		if (flags.minus)
			while (count--)
				ft_putchar_fd(' ', 1);
	}
	count += max(6, flags.width);
	return (count);
}

static int	__func_s_dot(char *arg, t_flags flags, int count, int len)
{
	int	iter;
	int	offset;

	offset = 0;
	iter = min(len, flags.precision);
	count += min(len, flags.precision);
	while (iter--)
		ft_putchar_fd(arg[offset++], 1);
	return (count);
}

int	func_s(char *arg, t_flags flags, int count)
{
	int	len;
	int	delta;

	len = 0;
	if (arg == NULL)
		return (__func_s_null(flags, count));
	len = ft_strlen(arg);
	delta = flags.width - len;
	if ((delta > 0) && !flags.minus)
		while (delta-- && ++count)
			ft_putchar_fd(' ', 1);
	if (flags.dot)
		count = __func_s_dot(arg, flags, count, len);
	else
	{
		ft_putstr_fd(arg, 1);
		count += len;
	}
	if ((delta > 0) && flags.minus)
		while (delta-- && ++count)
			ft_putchar_fd(' ', 1);
	return (count);
}
