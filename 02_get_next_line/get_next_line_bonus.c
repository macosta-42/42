/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <macosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 09:59:25 by macosta           #+#    #+#             */
/*   Updated: 2020/05/15 11:52:45 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char		*get_line_buffered(char *str, int fd, int *nb_read)
{
	char			buf[BUFFER_SIZE + 1];
	char			*tmp;

	while ((*nb_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[*nb_read] = '\0';
		if (str == NULL)
			str = ft_strdup(buf);
		else
		{
			tmp = str;
			str = ft_strjoin(str, buf);
			free(tmp);
		}
		if (ft_strchr(str, '\n'))
			break ;
	}
	return (str);
}

int			inject_line(char *str, char **line)
{
	int				i;

	i = 0;
	if (str != NULL)
	{
		while (str[i] != '\0' && str[i] != '\n')
			i++;
		if (str[i] == '\n')
		{
			*line = ft_substr(str, 0, i);
			return (1);
		}
		else
		{
			*line = ft_strdup(str);
			return (0);
		}
	}
	else
	{
		*line = ft_strdup("");
		return (0);
	}
}

char		*rest_of_buffer(char *str)
{
	int				i;
	int				str_len;
	char			*tmp;

	i = 0;
	str_len = ft_strlen(str);
	if (str != NULL)
	{
		while (str[i] != '\0' && str[i] != '\n')
			i++;
		if (str[i] == '\n')
		{
			tmp = str;
			str = ft_substr(str, i + 1, str_len - i - 1);
			free(tmp);
		}
	}
	return (str);
}

int			get_next_line(int fd, char **line)
{
	int				nb_read;
	static char		*str[1024];
	int				more_in_buffer;

	if (read(fd, str[fd], 0) || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	str[fd] = get_line_buffered(str[fd], fd, &nb_read);
	if (nb_read < 0)
		return (-1);
	more_in_buffer = inject_line(str[fd], line);
	if (more_in_buffer)
		str[fd] = rest_of_buffer(str[fd]);
	else
	{
		free(str[fd]);
		str[fd] = NULL;
		return (0);
	}
	return (1);
}
