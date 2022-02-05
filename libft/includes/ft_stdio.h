/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:02:19 by ahayashi          #+#    #+#             */
/*   Updated: 2022/02/01 12:01:42 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDIO_H
# define FT_STDIO_H

# include "ft_string.h"
# include <unistd.h>

int		ft_putchar_fd(char c, int fd);
int		ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_putstr_fd(char *s, int fd);

#endif
