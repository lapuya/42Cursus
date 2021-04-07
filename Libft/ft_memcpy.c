/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 09:58:11 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/04/07 12:56:43 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*memcpy(void *dst, const void *src, size_t len)
{
	int				i;
	unsigned char	*p_dst;
	unsigned char	*p_src;

	i = 0;
	p_dst = (unsigned char *) dst;
	p_src = (unsigned char *) src;
	while (i < len)
	{
		p_dst[i] = src[i];
		i++;
	}
	return (dst);
}
