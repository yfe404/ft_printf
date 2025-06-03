/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfeunteu <yfeunteu@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 21:38:28 by yfeunteu          #+#    #+#             */
/*   Updated: 2025/06/03 21:38:29 by yfeunteu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_digits_hex(unsigned long nb)
{
	if (nb < 16)
		return (1);
	return (1 + ft_count_digits_hex(nb / 16));
}

int	ft_count_digits_dec(int nb)
{
	if (nb == 0)
		return (1);
	if (nb <= -10)
		return (2 + ft_count_digits_dec(-(nb / 10)));
	if (nb < 0)
		return (2);
	if (nb < 10)
		return (1);
	return (1 + ft_count_digits_dec(nb / 10));
}

int	ft_count_digits_uint(unsigned int nbr)
{
	if (nbr < 10)
		return (1);
	return (1 + ft_count_digits_uint(nbr / 10));
}

void	ft_putnbr_hex(unsigned long nbr, unsigned char upper, int padding)
{
	const char	*charset = "0123456789abcdef";
	const char	*charset_upper = "0123456789ABCDEF";

	while (padding-- > 0)
		ft_putchar_fd('0', 1);
	if (nbr < 16)
	{
		if (upper)
			ft_putchar_fd(charset_upper[nbr], 1);
		else
			ft_putchar_fd(charset[nbr], 1);
		return ;
	}
	if (nbr)
	{
		ft_putnbr_hex(nbr / 16, upper, 0);
		if (upper)
			ft_putchar_fd(charset_upper[nbr % 16], 1);
		else
			ft_putchar_fd(charset[nbr % 16], 1);
	}
}

void	ft_putnbr_padding(int nb, int padding)
{
	if (nb < 0)
		ft_putchar_fd('-', 1);
	while (padding-- > 0)
		ft_putchar_fd('0', 1);
	if (nb <= -10 || nb >= 10)
	{
		if (nb < 0)
		{
			ft_putnbr_padding(-(nb / 10), 0);
			ft_putchar_fd(-(nb % -10) + '0', 1);
		}
		else
		{
			ft_putnbr_padding(nb / 10, 0);
			ft_putchar_fd((nb % 10) + '0', 1);
		}
	}
	else
	{
		if (nb < 0)
			ft_putchar_fd(-nb + '0', 1);
		else
			ft_putchar_fd(nb + '0', 1);
	}
}
