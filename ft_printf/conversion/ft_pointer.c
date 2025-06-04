/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfeunteu <yfeunteu@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 00:16:49 by yfeunteu          #+#    #+#             */
/*   Updated: 2025/06/04 22:35:19 by yfeunteu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "../utils.h"
#include "../parsing.h"
#include "../numbers_utils_print.h"
#include "../numbers_utils_count.h"

static int	__func_ptr_null(t_flags flags, int count)
{
	int	pad_count;

	pad_count = flags.width - 5;
	if (flags.width > 5)
		if (!flags.minus)
			while (pad_count--)
				ft_putchar_fd(' ', 1);
	ft_putstr_fd("(nil)", 1);
	if (flags.width > 5)
		if (flags.minus)
			while (pad_count--)
				ft_putchar_fd(' ', 1);
	count += max(5, flags.width);
	return (count);
}

int	func_ptr(void *arg, t_flags flags, int count)
{
	int	len;
	int	delta;

	if (arg == NULL)
		count = __func_ptr_null(flags, count);
	else
	{
		len = ft_count_digits_hex((unsigned long)arg) + 2;
		delta = flags.width - len;
		if ((delta > 0) && !flags.minus)
			while (delta-- && ++count)
				ft_putchar_fd(' ', 1);
		write(1, "0x", 2);
		ft_putnbr_hex((unsigned long)arg, 0, 0);
		if ((delta > 0) && flags.minus)
		{
			while (delta-- && ++count)
				ft_putchar_fd(' ', 1);
		}
		count += len;
	}
	return (count);
}
