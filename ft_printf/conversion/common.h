/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfeunteu <yfeunteu@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:58:09 by yfeunteu          #+#    #+#             */
/*   Updated: 2025/06/05 11:02:09 by yfeunteu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

typedef struct s_format
{
	int		n_zeros;
	int		n_pad_left;
	int		n_pad_right;
	char	pad_chr;
	char	sign_chr;
}	t_format;

t_format	init_format(void);
#endif
