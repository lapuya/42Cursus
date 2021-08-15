/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 09:02:40 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/05/18 13:43:24 by lapuya-p         ###   ########.fr       */
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

/*	save_and_point returns the pointer to line
	1. We search for the \n or null
	2. if its a \n
		-we store in line until \n
		-we save the rest of the string in the static variable
	3. if it's \0, we store the string saved in the static variable
*/

char	*ft_save_and_point(char *save, char **line)
{
	unsigned int	i;
	size_t			limit;
	char			*tmp;

	i = 0;

	while (save[i] != '\n' && save[i] != '\0')
		i++;
	printf("%d\n", i);
	if (save[i] == '\n')
	{
		printf("%s\n","primer if");
		limit = ft_strlen(save);
		printf("%zu\n", limit);
		*line = ft_substr(save, 0, i);
		printf("%s\n",*line);
		printf("------------");
		tmp = ft_substr(save, i + 1, limit);
		printf("%s\n",tmp);
		free(save);
		save = ft_strdup(tmp);
		free(tmp);
	}
	else
	{
		printf("seguundo");
		*line = save;
		save = NULL;
	}
	return (save);
}

/*	join_and_adjust adds the line we got (aux) with the new line read (buf)
	-we assign to a tmp variable the product of joining the two strings
	-we delete what we got and assign him the new string (tmp)
	-we delete the tmp and return the new generated string
*/

char	*ft_join_and_adjust(char *aux, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(aux, buf);
	free(aux);
	aux = ft_strdup(tmp);
	free(tmp);
	return (aux);
}

/*	get_next_line gets a line from a file according to the buffer_size
	-static to preserve its value out of its scope.
	-4096 is the limit of files open.
	-BUFFER_SIZE + 1 to add NULL-terminated to the string read
	Reads and:
		-if ret is -1, there was an error -> returns -1
		-we join what we had with the new read
		-we search for a \n from the line we read and:
			1. if found, we store until the \n
			2. if not, we read again and repeat
 */

int	get_next_line(int fd, char **line)
{
	static char		*aux[4096];
	char			buf[BUFFER_SIZE + 1];
	int				ret;

	ret = read(fd, buf, BUFFER_SIZE);
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
	if (ret == 0 && !aux[fd])
	{
		*line = ft_strdup("");
		return (ret);
	}
	aux[fd] = ft_save_and_point(aux[fd], line);
	if (!aux[fd])
		return (ret);
	return (1);
}
