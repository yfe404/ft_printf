/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfeunteu <yfeunteu@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 01:29:30 by yfeunteu          #+#    #+#             */
/*   Updated: 2025/06/04 01:30:16 by yfeunteu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef struct s_flags
{
	int	minus;
	int	zero;
	int	hash;
	int	plus;
	int	space;
	int	width;
	int	precision;
	int	dot;
}	t_flags;

t_flags		init_flags(void);
int			is_flag(char c);
const char	*parse_flags(const char *format, t_flags *flags);
const char	*parse_width(const char *format, t_flags *flags);
const char	*parse_precision(const char *format, t_flags *flags);
#endif
