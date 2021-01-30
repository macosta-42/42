/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:43:34 by macosta           #+#    #+#             */
/*   Updated: 2020/02/25 22:41:45 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <unistd.h>

int		ft_strlen(char *str);
int		ft_atoi(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int a);
void	ft_add(int a, int b);
void	ft_sub(int a, int b);
void	ft_mult(int a, int b);
void	ft_div(int a, int b);
void	ft_mod(int a, int b);
void	ft_calc(char *str1, char c, char *str2);

#endif
