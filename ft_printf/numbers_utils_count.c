/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_utils_count.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfeunteu <yfeunteu@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 21:53:32 by yfeunteu          #+#    #+#             */
/*   Updated: 2025/06/03 21:59:20 by yfeunteu         ###   ########.fr       */
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
