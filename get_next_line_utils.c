/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreta <lbarreta@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 21:56:01 by lbarreta          #+#    #+#             */
/*   Updated: 2020/05/10 20:51:02 by lbarreta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
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

char	*ft_split_line (char *rest, int return_value)
{
	int 	i;
	int		j;
	char	*ptr;

	if (!rest)
		return (NULL);
	i = 0;
	while (rest[i] != '\0' || rest[i] != '\n')
		i++;
	if (!(ptr = malloc((i + 1) * sizeof(char))))
		return (NULL);
	ptr[i + 1] = '\0';
	j = 0;
	while (j <= i)
	{
		ptr[j] = rest[j];
		j++;
	}
	if (rest[i] == '\n')
		return_value = 1;
	else if (rest[i] == '\0')
		return_value = -1;
	*rest = *rest + i;
	return (ptr);
}
