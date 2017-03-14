/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csandjon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 00:20:54 by csandjon          #+#    #+#             */
/*   Updated: 2016/11/07 22:00:59 by csandjon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalnum(int c)
{
	unsigned int a;

	a = (unsigned int)c;
	if ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z')
			|| (a >= '0' && a <= '9'))
		return (1);
	return (0);
}