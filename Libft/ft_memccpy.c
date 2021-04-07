/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 12:04:05 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/04/07 13:02:49 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*memccpy(void dst, const void *src, int c, size_t len)
{
	int				i;
	unsigned char	*p_dst;
	unsigned char	*p_src;

	i = 0;
	p_dst = (unsigned char *) dst;
	p_src = (unsigned char *) src;
	while (i < len)
	{
		if (p_src[i] == (unsigned char)c)
			return (&p_dst[i + 1]);
		p_dst[i] = src[i];
		i++;
	}
	return (NULL);
}
