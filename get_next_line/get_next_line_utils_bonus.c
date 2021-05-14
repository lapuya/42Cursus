/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 09:02:37 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/05/13 12:23:31 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen(s1) + 1;
	ptr = malloc(sizeof(char) * len);
	if (!ptr)
		return (0);
	ptr = ft_memcpy(ptr, s1, len);
	return (ptr);
}

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*p_dst;
	unsigned char	*p_src;

	if (dst == NULL && src == NULL)
		return (dst);
	i = 0;
	p_dst = (unsigned char *) dst;
	p_src = (unsigned char *) src;
	while (i < len)
	{
		p_dst[i] = p_src[i];
		i++;
	}
	return (dst);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;
	size_t	total_len;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	total_len = len_s1 + len_s2 + 1;
	str = malloc(sizeof(char) * total_len);
	if (!str)
		return (NULL);
	ft_memmove(str, s1, len_s1);
	ft_memmove(str + len_s1, s2, len_s2);
	str[total_len - 1] = '\0';
	return (str);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*p_dst;
	char		*p_src;

	if (!dst && !src)
		return (NULL);
	i = 0;
	p_dst = (char *)dst;
	p_src = (char *)src;
	if (p_src < p_dst)
	{
		p_src = p_src + len - 1;
		p_dst = p_dst + len - 1;
		while (len > 0)
		{
			*p_dst-- = *p_src--;
			len--;
		}
	}
	else
	{
		while (len-- > 0)
			*p_dst++ = *p_src++;
	}
	return (dst);
}
