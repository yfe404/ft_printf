/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfeunteu <yfeunteu@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 00:06:31 by yfeunteu          #+#    #+#             */
/*   Updated: 2025/06/04 23:11:44 by yfeunteu         ###   ########.fr       */
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
	if (flags.dot && flags.precision < 6)
		return (0);
	flags.width = max(0, flags.width - 6);
	count += flags.width + 6;
	if (flags.width && !flags.minus)
		while (flags.width--)
			ft_putchar_fd(' ', 1);
	ft_putstr_fd("(null)", 1);
	if (flags.width && flags.minus)
		while (flags.width--)
			ft_putchar_fd(' ', 1);
	return (count);
}

int	func_s(char *arg, t_flags flags, int count)
{
	int	len;

	if (arg == NULL)
		return (__func_s_null(flags, count));
	len = ft_strlen(arg) * !flags.dot + flags.dot \
		* min(flags.precision, ft_strlen(arg));
	count += max(flags.width, len);
	flags.width = max(0, flags.width - len);
	if (flags.width && !flags.minus)
		while (flags.width--)
			ft_putchar_fd(' ', 1);
	print_sub_str(arg, len);
	if (flags.width && flags.minus)
		while (flags.width--)
			ft_putchar_fd(' ', 1);
	return (count);
}
