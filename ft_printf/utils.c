/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfeunteu <yfeunteu@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 22:38:28 by yfeunteu          #+#    #+#             */
/*   Updated: 2025/06/05 11:13:58 by yfeunteu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	print_sub_str(const char *str, int n)
{
	if (n <= 0 || !str || !(*str))
		return ;
	while (n--)
		ft_putchar_fd(*str++, 1);
}

void	ft_putnbr_nosign_fd(int n, int fd)
{
	int				sign;
	char			temp[12];
	unsigned int	pos;

	sign = n < 0;
	pos = 10;
	temp[11] = '\0';
	if (n == 0)
		temp[pos--] = '0';
	while (n)
	{
		temp[pos--] = (!sign * (n % 10)) + (-sign * (n % -10)) + '0';
		n = n / 10;
	}
	ft_putstr_fd(&temp[pos + 1], fd);
}
