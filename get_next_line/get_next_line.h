/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csandjon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 16:21:05 by csandjon          #+#    #+#             */
/*   Updated: 2017/02/26 16:40:17 by csandjon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include "libft/libft.h"

# define BUFF_SIZE	10000

typedef	struct		s_node
{
	char			*data;
	int				fd;
	struct s_node	*next;
}					t_node;

int					get_next_line(const int fd, char **line);

#endif
