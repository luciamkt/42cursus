/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltakahas <ltakahas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 15:25:23 by ltakahas          #+#    #+#             */
/*   Updated: 2020/05/09 21:49:16 by ltakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>

int		ft_isdigit(int c);
int		ft_putchar(char c);
size_t	ft_strlen(char *str);
int		ft_putstr(char *str, size_t len);
int		ft_strchr(const char *s, int c);
int		ft_putnbr_p(size_t nb, char *base);
int		ft_putnbr(unsigned int nb, char *base);
int		ft_count_digit_p(size_t p, unsigned int base);
int		ft_count_digit(unsigned int nb, unsigned int base);

#endif
