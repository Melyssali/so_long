/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlesein <mlesein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:28:00 by mlesein           #+#    #+#             */
/*   Updated: 2024/02/28 15:37:43 by mlesein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
size_t	ft_strlen_p(const char *str);
int		ft_putstr(const char *s, int fd);
int		ft_putnbr_p(int n, int fd);
int		ft_putnbr_hexa(unsigned long n, unsigned long base, char format);
int		ft_putchar_p(char c, int fd);

#endif