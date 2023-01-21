/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:39:24 by akayle            #+#    #+#             */
/*   Updated: 2021/12/29 11:43:27 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*buffer_line(int fd, char *line)
{
	int		readed;
	char	*buffer;

	readed = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while ((ft_strchr(line, '\n') != 1) && (readed != 0))
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[readed] = '\0';
		if (!line)
		{
			line = malloc(sizeof(char));
			line[0] = '\0';
		}
		line = ft_strjoin(line, buffer);
	}
	free (buffer);
	return (line);
}

char	*before_n(char *remains)
{
	char	*line;
	int		i;

	i = 0;
	if (!remains[0])
		return (NULL);
	while (remains[i] && remains[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (remains[i] && remains[i] != '\n')
	{
		line[i] = remains[i];
		i++;
	}
	if (remains[i] == '\n')
	{
		line[i] = remains[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*after_n(char *remains)
{
	int		i;
	int		j;
	char	*remainder;

	i = 0;
	j = 0;
	if (!remains)
		return (NULL);
	while (remains[i] && remains[i] != '\n')
		i++;
	if (!remains[i])
	{
		free(remains);
		return (NULL);
	}
	remainder = (char *)malloc(sizeof(char) * (ft_strlen(remains) - i + 1));
	if (!remainder)
		return (NULL);
	i++;
	while (remains[i])
		remainder[j++] = remains[i++];
	remainder[j] = '\0';
	free (remains);
	return (remainder);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*remains[1024];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (NULL);
	remains[fd] = buffer_line(fd, remains[fd]);
	if (!remains[fd])
		return (NULL);
	line = before_n(remains[fd]);
	remains[fd] = after_n(remains[fd]);
	return (line);
}
