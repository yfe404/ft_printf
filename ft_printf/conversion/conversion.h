/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfeunteu <yfeunteu@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:21:59 by yfeunteu          #+#    #+#             */
/*   Updated: 2025/06/04 13:22:06 by yfeunteu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_H
# define CONVERSION_H

int	func_int(int arg, t_flags flags);
int	func_u(unsigned int arg, t_flags flags);
int	func_x(unsigned int arg, t_flags flags);
int	func_upper_x(unsigned int arg, t_flags flags);
int	func_c(char arg, t_flags flags, int count);
int	func_s(char *arg, t_flags flags, int count);
int	func_ptr(void *arg, t_flags flags, int count);
#endif
