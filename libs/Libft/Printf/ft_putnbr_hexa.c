/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlesein <mlesein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 20:19:54 by mlesein           #+#    #+#             */
/*   Updated: 2023/11/27 20:39:49 by mlesein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hexa(unsigned long n, unsigned long base, char format)
{
	int		count;
	char	*hexa;

	count = 0;
	hexa = "0123456789abcdef";
	if (ft_strlen_p(hexa) < 2)
		return (0);
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (format == 'X')
		hexa = "0123456789ABCDEF";
	if (n >= base)
		count += ft_putnbr_hexa(n / base, base, format);
	write(1, &hexa[n % base], 1);
	return (count + 1);
}

// int	main(void)
// {
// 	ft_putnr_fd(122, 1);
// 	return (0);
// }
