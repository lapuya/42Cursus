/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <lapuya-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 15:37:28 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/09/01 15:40:32 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_split_count(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			i++;
		}
	}
	return (count);
}
