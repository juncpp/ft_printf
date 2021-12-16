/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeredit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:04:27 by mmeredit          #+#    #+#             */
/*   Updated: 2021/11/21 19:16:28 by mmeredit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
int		ft_printf(const char *inp, ...);
int		ft_putCount(char c);
int		ft_putCountNbr(int n, int j);
int		ft_putCountUnbr(unsigned int n);
int		ft_putCountStr(char *str);
int		ft_putS(va_list ptr, char *inp);
void	ft_toX(char *s);
void	ft_tox(char *s);
int		checkHex(int x);
int		ft_putHexa(unsigned long num, char c);
char	*ft_percent(va_list ptr, char *inp, int *i);
char	*ft_skip(char *inp, int *i);
#endif
