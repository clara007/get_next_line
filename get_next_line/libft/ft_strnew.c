/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csandjon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 21:40:41 by csandjon          #+#    #+#             */
/*   Updated: 2017/02/26 15:25:19 by csandjon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *tmp;

	tmp = (char*)malloc(size + 1);
	if (!tmp)
		return (NULL);
	ft_bzero(tmp, (size + 1));
	return (tmp);
}
