/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 11:02:47 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/04/14 10:26:25 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static	int	ft_determine_size(const char *src, char c)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (src[i] == c && src[i] != '\0') //saltarse separadores iniciales
		i++;
	while (src[i] != c && src[i] != '\0')	//si ya es una palabra, aumentar en uno, saltarse separadores y saltarse la palabra. Sumar 1 nuevamente
	{
		size++;
		while (src[i] != c && src[i] != '\0')
			i++;
		while (src[i] == c && src[i] != '\0')
			i++;
	}
	return (size);
}

static	void	ft_count_elem_size(const char *src, char c, int *tab)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (src[i] == c && src[i] != '\0')	//saltar separadores iniciales
		i++;
	while (src[i] != c && src[i] != '\0')
	{
		tab[n] = 0;
		while (src[i] != c && src[i] != '\0') // mientras que no sea un separador, aumentamos el tamaño
		{
			i++;
			tab[n]++;	
		}
		n++;
		while (src[i] == c && src[i] != '\0')
			i++;
	}
}

static	int	ft_fill(const char *src, char c, int *tab, char **split)
{
	int	i;
	int	n;
	int	j;

	i = 0;
	n = 0;
	while (src[i] == c && src[i] != '\0') //saltarnos si las primeras son separadores
		i++;
	while (src[i] != c && src[i] != '\0')
	{
		j = 0;
		if (!(split[n] = (char *)malloc(sizeof(char) * (tab[n] + 1))))	//crear cada tabla
			return (0);
		while (src[i] != c && src[i] != '\0')	//rellenar la tabla
		{
			split[n][j] = src[i];
			i++;
			j++;
		}
		split[n][j] = '\0';
		n++;
		while (src[i] == c && src[i] != '\0')	//despues de cada palabra, saltarnos el intermedio
			i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	int		*elem_size;
	int		size;
	int		i;

	if (!s)
		return (NULL);
	size = ft_determine_size(s, c);
	elem_size = malloc(sizeof(char *) * size);
	matrix = malloc(sizeof(char **) * size + 1);
	if (!elem_size || !matrix)
	{
		free(elem_size);
		free(matrix);
		return (NULL);
	}
	ft_count_elem_size(s, c, elem_size);
	i = ft_fill(s, c, elem_size, matrix);
	if (i == 0)
	{
		free(elem_size);
		free(matrix);
		return (NULL);
	}
	matrix[size] = NULL;
	return (matrix);
}

/*int main()
{
	char *string = "0 0 0 0 0 0 0 0 0";
  //  char **expected = ((char*[6]){"split", "this", "for", "me", "!", ((void *)0)});
    char **result = ft_split(string, ' ');
	int i = 0;
	size_t j;

	while (i < 9)
	{
		j = 0;
		while (j < ft_strlen(result[i]))
		{
			printf("%c", result[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}*/