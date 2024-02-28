/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlesein <mlesein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 20:06:29 by mlesein           #+#    #+#             */
/*   Updated: 2024/02/28 15:42:16 by mlesein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *s, int fd)
{
	int	count;

	count = 0;
	if (!s)
		return (count += write(1, "(null)", 6));
	return (count += write(fd, s, ft_strlen_p(s)));
}

// int	main(void)
// {
// 	char	str[] = "Une phrase ta race";
// 	ft_putstr_fd(str, 1);
// 	return (0);
// }