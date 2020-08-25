/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreta <lbarreta@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 21:56:01 by lbarreta          #+#    #+#             */
/*   Updated: 2020/08/25 13:55:09 by lbarreta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	int		i;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	if (!(ptr = malloc((len_s1 + len_s2 + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		ptr[i] = s1[i];
		i++;
	}
	while (i <= (len_s1 + len_s2))
	{
		ptr[i] = s2[i - len_s1];
		i++;
	}
	return (ptr);
}

char	*ft_strcut (char *rest, int i)
{
	int j;

	j = 0;
	while (rest[i] != '\0')
	{
		rest[j] = rest[i];
		i++;
		j++;
	}
	rest[j] = '\0';
	return (rest);
}

int		ft_split_line (char *rest, char **line)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	while (rest[i] != '\0' && rest[i] != '\n')
		i++;
	if (!(ptr = malloc((i) * sizeof(char))))
		return (-1);
	ptr[i] = '\0';
	j = 0;
	while (j < i)
	{
		ptr[j] = rest[j];
		j++;
	}
	*line = ptr;
	if (rest[i] == '\n')
	{
		i++;
		rest = ft_strcut(rest, i);
		return (1);
	}
	else
		return (0);
}
