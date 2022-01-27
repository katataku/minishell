/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:04:44 by ahayashi          #+#    #+#             */
/*   Updated: 2022/01/26 22:23:12 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H

# include "ft_ctype.h"
# include "ft_string.h"
# include <limits.h>
# include <stdlib.h>

int		ft_abs(int n);
int		ft_atoi(const char *str);
long	ft_atol(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_itoa(int n);

#endif
