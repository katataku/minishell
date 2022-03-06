/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:02:57 by ahayashi          #+#    #+#             */
/*   Updated: 2022/03/04 17:02:57 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "define.h"
# include "libft.h"

void	puterr(char *target, char *message);
void	puterr_exit(char *target, char *message, int exit_status);

#endif
