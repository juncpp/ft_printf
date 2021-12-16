/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeredit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:19:49 by mmeredit          #+#    #+#             */
/*   Updated: 2021/11/23 17:07:08 by mmeredit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_percent(va_list ptr, char *inp, int *i)
{
	if (*inp == 'c')
		*i = *i + ft_putCount(va_arg(ptr, int));
	if (*inp == 's')
		*i = *i + ft_putCountStr(va_arg(ptr, char *));
	if (*inp == 'i' || *inp == 'd')
		*i = *i + ft_putCountNbr(va_arg(ptr, int), 0);
	if (*inp == 'u')
		*i = *i + ft_putCountUnbr(va_arg(ptr, unsigned int));
	if (*inp == '%')
		*i = *i + ft_putCount('%');
	if (*inp == 'x' || *inp == 'X')
		*i = *i + ft_putHexa(va_arg(ptr, unsigned int), *inp);
	if (*inp == 'p')
		*i = *i + ft_putHexa((unsigned long)va_arg(ptr, void *), *inp);
	if (*inp)
		inp++;
	return (inp);
}

char	*ft_skip(char *inp, int *i)
{
	while (*inp != '%' && *inp)
	{
		*i = *i + ft_putCount(*inp);
		inp++;
	}
	return (inp);
}

int	ft_printf(const char *inp, ...)
{
	va_list	ptr;
	int		i;

	i = 0;
	va_start(ptr, inp);
	if (inp != NULL)
		i = ft_putS(ptr, (char *)inp);
	va_end(ptr);
	return (i);
}
