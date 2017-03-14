/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csandjon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 18:03:52 by csandjon          #+#    #+#             */
/*   Updated: 2017/02/26 16:44:01 by csandjon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_node		*ft_newnode(int fd)
{
	t_node			*new;

	if (!(new = (t_node*)malloc(sizeof(t_node))))
		return (NULL);
	if (!(new->data = ft_strnew(0)))
		return (NULL);
	new->fd = fd;
	new->next = NULL;
	return (new);
}

static	t_node		*get_fd_file(t_node **head, int fd)
{
	t_node			*file;

	file = *head;
	while (file != NULL)
	{
		if (file->fd == fd)
			return (file);
		file = file->next;
	}
	file = ft_newnode(fd);
	file->next = *head;
	*head = file;
	return (file);
}

static int			free_fd_node(t_node **head, int fd)
{
	t_node			*file;
	t_node			*prev;

	file = *head;
	if (file != NULL && file->fd == fd)
	{
		*head = file->next;
		free(file);
	}
	else
	{
		while (file != NULL && file->fd != fd)
		{
			prev = file;
			file = file->next;
		}
		prev->next = file->next;
		free(file);
	}
	return (1);
}

static int			read_fd_file(int const fd, char **total_data)
{
	char			*buff;
	int				ret;
	char			*new_total_data;

	buff = ft_strnew(BUFF_SIZE);
	ret = read(fd, buff, BUFF_SIZE);
	if (ret > 0)
	{
		new_total_data = ft_strjoin(*total_data, buff);
		if (!new_total_data)
			return (-1);
		free(buff);
		free(*total_data);
		*total_data = new_total_data;
	}
	return (ret);
}

int					get_next_line(int const fd, char **line)
{
	char			*data;
	static t_node	*head;
	t_node			*file;
	int				r;

	if (fd < 0 || line == NULL)
		return (-1);
	file = get_fd_file(&head, fd);
	data = file->data;
	while (ft_strchr(data, '\n') == NULL && (r = read_fd_file(fd, &data)) != 0)
		if (r < 0)
			return (-1);
	if (r == 0 && data != NULL && ft_strchr(data, '\n') == NULL)
	{
		if (ft_strlen(data) == 0 && free_fd_node(&head, fd) == 1)
			return (0);
		*line = ft_strdup(data);
		file->data = ft_strnew(0);
		free(data);
		return (1);
	}
	*line = ft_split_str(data, '\n');
	file->data = ft_strdup(ft_strchr(data, '\n') + 1);
	free(data);
	return (1);
}
