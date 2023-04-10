/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:50:34 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/04/06 15:19:29 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_putnbru(unsigned int n);
void	*ft_memset(void *s, int c, size_t n);
int		ft_putnbr_base(long int n, char *base);
char	*ft_strrchr(const char *s, int c);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_putstr_fd(char *s, int fd);
int		ft_putchar_fd(char c, int fd);
int		ft_putnbr_fd(long long n, int fd);
char	*ft_strtoupper(const char *str);
int		ft_pttostr(void *n);

#endif
