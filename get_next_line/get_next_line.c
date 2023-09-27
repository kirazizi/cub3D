/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:23:42 by sbzizal           #+#    #+#             */
/*   Updated: 2023/08/16 11:23:45 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

char	*ft_read(int fd, char *keep)
{
	char	*buffer;
	int		bytes_read;

	bytes_read = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(keep, '\n') && bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(keep), free(buffer), NULL);
		buffer[bytes_read] = '\0';
		keep = ft_strjoin(keep, buffer);
	}
	free(buffer);
	return (keep);
}

char	*ft_linecheck(char *keep)
{
	char	*line;
	int		i;

	i = 0;
	while (keep[i] && keep[i] != '\n')
		i++;
	if (keep[i] == '\n')
		i++;
	line = malloc(i + 1 * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (keep[i] && keep[i] != '\n')
	{
		line[i] = keep[i];
		i++;
	}
	if (keep[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_restkeep(char *keep)
{
	char	*ret;
	int		i;

	i = 0;
	while (keep[i] && keep[i] != '\n')
		i++;
	if (keep[i] == '\n')
		i++;
	ret = ft_strdup(&keep[i]);
	free (keep);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*keep;
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	keep = ft_read(fd, keep);
	if (!keep)
		return (NULL);
	line = ft_linecheck(keep);
	keep = ft_restkeep(keep);
	return (line);
}
