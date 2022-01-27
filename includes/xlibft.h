/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xlibft.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 23:39:45 by ahayashi          #+#    #+#             */
/*   Updated: 2022/01/20 23:48:02 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XLIBFT_H
# define XLIBFT_H

# include "libft.h"
# include "pipex.h"
# include "typedefs.h"

char	*ft_xcalloc(size_t count, size_t size);
char	**ft_xsplit(const char *s, char c);
char	*ft_xstrdup(const char *s);
char	*ft_xstrjoin(const char *s1, const char *s2);
#endif
