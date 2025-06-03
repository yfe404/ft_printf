/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfeunteu <yfeunteu@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 21:39:59 by yfeunteu          #+#    #+#             */
/*   Updated: 2025/06/03 21:40:48 by yfeunteu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUMBERS_UTILS_H
# define NUMBERS_UTILS_H

int		ft_count_digits_hex(unsigned long nb);
int		ft_count_digits_dec(int nb);
int		ft_count_digits_uint(unsigned int nbr);
void	ft_putnbr_hex(unsigned long nbr, unsigned char upper, int padding);
void	ft_putnbr_padding(int nb, int padding);

#endif
