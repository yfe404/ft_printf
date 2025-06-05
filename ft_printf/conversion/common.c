/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfeunteu <yfeunteu@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:04:33 by yfeunteu          #+#    #+#             */
/*   Updated: 2025/06/05 11:04:35 by yfeunteu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_format	init_format(void)
{
	t_format	format;

	format.n_zeros = 0;
	format.n_pad_left = 0;
	format.n_pad_right = 0;
	format.pad_chr = 0;
	format.sign_chr = 0;
	return (format);
}
