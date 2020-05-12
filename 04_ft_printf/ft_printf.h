/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltakahas <ltakahas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 15:16:07 by ltakahas          #+#    #+#             */
/*   Updated: 2020/05/09 21:42:33 by ltakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "utils/utils.h"

# define ALL		"cspdiuxX%-0.* "
# define SPECIFIERS	"cspdiuxX%"
# define DEC		"0123456789"
# define HEX_LOWER	"0123456789abcdef"
# define HEX_UPPER	"0123456789ABCDEF"

typedef struct	s_infos
{
	char		specifier;
	int			minus;
	int			zero;
	int			width;
	int			dot;
	int			precision;
	int			signal;
	int			len;
}				t_infos;

void			ft_flag_minus(t_infos *infos);
void			ft_reset_flags(t_infos *infos);
void			ft_print_percent(t_infos *infos);
int				ft_printf(const char *format, ...);
void			ft_print_c(t_infos *infos, va_list args);
void			ft_print_s(t_infos *infos, va_list args);
void			ft_print_u(t_infos *infos, va_list args);
void			ft_print_x(t_infos *infos, va_list args);
void			ft_print_p(t_infos *infos, va_list args);
void			ft_print_di(t_infos *infos, va_list args);
void			ft_flag_width(t_infos *infos, va_list args);
int				ft_flag_digit(char *str, int i, t_infos *infos);
void			ft_print_pattern_p1(t_infos *infos);
void			ft_print_pattern_p2(size_t p, int digits, t_infos *infos);
void			ft_print_pattern_p3(size_t p, int digits, t_infos *infos);
void			ft_print_pattern_p4(size_t p, int digits, t_infos *infos);
void			ft_print_pattern_p5(size_t p, int digits, t_infos *infos);
int				ft_flag_precision(char *str, int i, t_infos *infos,
				va_list args);
void			ft_print_pattern1(int digits, int width, t_infos *infos);
void			ft_print_pattern2(unsigned int nb, int digits, int width,
				t_infos *infos);
void			ft_print_pattern3(unsigned int nb, int digits, int width,
				t_infos *infos);
void			ft_print_pattern4(unsigned int nb, int digits, int width,
				t_infos *infos);
void			ft_print_pattern5(unsigned int nb, int digits, int width,
				t_infos *infos);

#endif
