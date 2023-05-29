/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakahmed <hakahmed@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:00:10 by hakahmed          #+#    #+#             */
/*   Updated: 2023/05/29 17:00:26 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"

# define B1 SIGUSR1
# define B0 SIGUSR2

typedef struct s_info
{
	int		flag;
	char	c;
}	t_info;

#endif
