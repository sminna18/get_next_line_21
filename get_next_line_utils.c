/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:36:25 by sminna            #+#    #+#             */
/*   Updated: 2021/10/21 15:21:34 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_for_gnl(char *s1, char *s2, int r)
{
	int		i[3];
	char	*x;

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	if (!s2)
		return (0);
	i[1] = ft_strlen(s1);
	i[2] = ft_strlen(s2);
	x = malloc(i[1] + i[2] + 2);
	ft_bzero (x, (i[1] + i[2] + 2));
	if (x == 0)
	{
		if (r)
			free (s1);
		return (0);
	}
	while (i[0] < i[1])
		x[i[0]++] = s1[i[0]];
	i[0] = 0;
	while (i[0] < i[2])
		x[i[1] + i[0]++] = s2[i[0]];
	if (r)
		free (s1);
	return (x);
}

size_t	ft_strlen(const char *c)
{
	int	x;

	x = 0;
	if (!c)
		return (0);
	while (c[x])
		x++;
	return (x);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	r;
	int	ccpy;

	i = 0;
	r = 0;
	ccpy = (char) c;
	while (s[r])
		r++;
	while (i <= r)
	{
		if (s[i] == ccpy)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

void	ft_bzero(void *b, size_t len)
{
	size_t	i;
	char	*d;

	i = 0;
	d = (char *) b;
	while (i < len)
	{
		d[i] = 0;
		i++;
	}
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		l;
	char	*x;

	i = 0;
	l = 0;
	if (!s1)
		return (0);
	while (s1[i])
		i++;
	x = malloc(i + 1);
	if (x != 0)
	{
		while (l < i)
		{
			x[l] = s1[l];
			l++;
		}
		x[l] = 0;
	}
	return (x);
}
