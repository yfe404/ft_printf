/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfeunteu <yfeunteu@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 22:38:28 by yfeunteu          #+#    #+#             */
/*   Updated: 2025/06/04 23:02:07 by yfeunteu         ###   ########.fr       */
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
