/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreta <lbarreta@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 21:56:17 by lbarreta          #+#    #+#             */
/*   Updated: 2020/08/31 22:39:02 by lbarreta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
#include <stdlib.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);
void	ft_strfree(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_split_line(char *rest, char **line);

#endif
