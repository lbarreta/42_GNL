/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreta <lbarreta@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 21:56:01 by lbarreta          #+#    #+#             */
/*   Updated: 2020/09/20 21:42:01 by lbarreta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_strfree(char **str)
{
	if (*str == 0)
		return ;
	if (*str)
		free(*str);
	*str = NULL;
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

void	ft_strcut(char **rest, int i)
{
	int		j;
	int		len;
	char	*temp;

	j = 0;
	len = i;
	while ((*rest)[len] != '\0')
		len ++;
	if (!(temp = malloc((len - i + 1) * sizeof(char))))
		return;
	while ((*rest)[i] != '\0')
	{
		temp[j] = (*rest)[i];
		i++;
		j++;
	}
	temp[j] = '\0';
	ft_strfree(rest);
	*rest = temp;
}

int		ft_split_line(char **rest, char **line)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	while ((*rest)[i] != '\0' && (*rest)[i] != '\n')
		i++;
	if (!(ptr = malloc((i + 1) * sizeof(char))))
		return (-1);
	ptr[i] = '\0';
	j = 0;
	while (j < i)
	{
		ptr[j] = (*rest)[j];
		j++;
	}
	*line = ptr;
	if ((*rest)[i] == '\n')
	{
		ft_strcut(rest, i + 1);
		return (1);
	}
	ft_strfree(rest);
	*rest = NULL;
	return (0);
}
