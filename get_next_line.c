/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreta <lbarreta@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 21:56:12 by lbarreta          #+#    #+#             */
/*   Updated: 2020/09/19 13:08:37 by lbarreta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_firstalloc(char *s1)
{
	s1 = malloc(1 * sizeof(char));
	s1[0] = '\0';
	return (s1);
}

int		get_next_line(int fd, char **line)
{
	int			read_return;
	char		buf[BUFFER_SIZE + 1];
	char		*temp;
	static char	*rest;
	int			len;

	printf("Rest - INICIO !!!\n%s\n",rest);

	if (fd < 0 || line == NULL || BUFFER_SIZE == 0)
		return (-1);
	if (rest == 0)
	{
		rest = ft_firstalloc(rest);
		printf("Passei por aqui\n");
	}
	while ((read_return = read(fd, buf, BUFFER_SIZE)))
	{
		printf("Passei por aqui no while\n");
		if (read_return < 0)
		{
			ft_strfree(rest);
			return (-1);
		}
		buf[read_return] = '\0';
		temp = ft_strjoin(rest, buf);
		ft_strfree(rest);
		rest = temp;
		len = ft_strlen(rest);
		while (len >= 0)
		{
			if (rest[len] == '\n')
				return (ft_split_line(rest, line));
			len--;
		}
	}
	return (ft_split_line(rest, line));
}
