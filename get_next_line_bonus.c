/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:43:13 by khovakim          #+#    #+#             */
/*   Updated: 2022/03/28 15:44:17 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line_bonus.h"

char	*ft_strjoinfree(char *saved, char *buffer)
{
	char	*p;

	if (!buffer)
		return (NULL);
	p = ft_strjoin(saved, buffer);
	if (saved)
		free(saved);
	return (p);
}

int	ft_strlen_n(char *saved)
{
	int	i;

	i = 0;
	if (!saved)
		return (0);
	while (saved[i] != '\n')
		i++;
	return (i);
}

char	*ft_edit(char **saved)
{
	char	*line;
	char	*todelete;

	if (!(*saved))
		return (NULL);
	line = NULL;
	if (ft_strchr(*saved, '\n'))
	{
		line = ft_substr(*saved, 0, ft_strlen_n(*saved) + 1);
		todelete = ft_strdup(*saved + ft_strlen_n(*saved) + 1);
		if (*todelete == '\0')
		{
			free(todelete);
			todelete = NULL;
		}
		free(*saved);
		*saved = todelete;
	}
	return (line);
}

char	*ft_read(int fd, char **saved, char *line)
{
	char	buffer[BUFFER_SIZE + 1];
	int		readen;

	readen = 1;
	while (readen != 0)
	{
		readen = read(fd, buffer, BUFFER_SIZE);
		if (readen == -1)
			return (NULL);
		buffer[readen] = '\0';
		if (readen > 0)
			*saved = ft_strjoinfree(*saved, buffer);
		line = ft_edit(saved);
		if (line)
			return (line);
	}
	line = ft_strdup(*saved);
	free(*saved);
	*saved = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*saved[65537];

	if (fd < 0 || fd > 65536 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_edit(&saved[fd]);
	if (line)
		return (line);
	line = ft_read(fd, &saved[fd], line);
	return (line);
}
