/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:17:17 by manufern          #+#    #+#             */
/*   Updated: 2024/01/11 19:59:51 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "../inc/fdf.h"
#include "../inc/get_next_line.h"

int	ft_string_count(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if ((s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			|| (i == 0 && s[i] != c))
		{
			j ++;
		}
		i ++;
	}
	return (j);
}

int	ft_word_count(char const *s, char c, int i)
{
	int	j;

	j = 0;
	while (s[i] != c && s[i])
	{
		j ++;
		i ++;
	}
	return (j);
}

char	**ft_free(char **aux, int j)
{
	int	i;

	i = 0;
	(void)j;
	if (!aux || *aux == NULL)
		return (NULL);
	while (aux[i] != NULL)
	{
		free(aux[i]);
		i++;
	}
	free(aux);
	return (NULL);
}

char	**ft_matrix(char **aux, char const *s, char c, int i)
{
	int	j;
	int	k;
	int	l;

	j = 0;
	while (s[i] != '\0')
	{
		k = 0;
		while (s[i] == c)
			i ++;
		if (s[i] == '\0')
		{
			aux[j] = NULL;
			return (aux);
		}
		aux[j] = (char *) malloc((ft_word_count(s, c, i) + 1) * sizeof(char));
		if (!aux[j])
			return (ft_free(aux, j));
		l = ft_word_count(s, c, i);
		while (k < l)
			aux[j][k ++] = s[i ++];
		aux[j ++][k] = '\0';
	}
	aux[j] = NULL;
	return (aux);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**aux;

	words = ft_string_count(s, c);
	aux = (char **)malloc((words + 1) * sizeof(char *));
	if (!aux)
		return (NULL);
	aux[words] = NULL;
	return (ft_matrix(aux, s, c, 0));
}
