/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 09:02:40 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/05/04 10:03:35 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if ((size_t)start >= size)
		return (ft_strdup(""));
	if (len > size)
		len = size;
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if ((unsigned char)c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_save_and_point(char *save, char **line)
{
	unsigned int	i;
	size_t			limit;
	char			*tmp;

	i = 0;
	while (save[i] != '\n' && save[i] != '\0')
		i++;
	if (save[i] == '\n')
	{
		limit = ft_strlen(save);
		*line = ft_substr(save, 0, i);
		tmp = ft_substr(save, i + 1, limit);
		free(save);
		save = ft_strdup(tmp);
		free(tmp);
	}
	else
	{
		*line = save;
		save = NULL;
	}
	return (save);
}

char	*ft_join_and_adjust(char *aux, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(aux, buf);
	free(aux);
	aux = ft_strdup(tmp);
	free(tmp);
	return (aux);
}

int	get_next_line(int fd, char **line)
{
	static char		*aux[4096];
	char			buf[BUFFER_SIZE + 1];
	int				ret;

	ret = read(fd, buf, BUFFER_SIZE);
	if (ret == 0 && !aux[fd])
	{
		*line = ft_strdup("");
		return (ret);
	}
	while (ret)
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		aux[fd] = ft_join_and_adjust(aux[fd], buf);
		if (ft_strchr(buf, '\n'))
			break ;
		ret = read(fd, buf, BUFFER_SIZE);
	}
	aux[fd] = ft_save_and_point(aux[fd], line);
	if (!aux[fd])
		return (ret);
	return (1);
}
