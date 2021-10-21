/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:36:28 by sminna            #+#    #+#             */
/*   Updated: 2021/10/21 15:21:35 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line_second_part(int *xx, char *str, char *strfull, int fd)
{
	int		i;
	int		c;
	char	*end;

	i = xx[0];
	c = 1;
	end = 0;
	while (!end && c > 0)
	{
		ft_bzero (str, (BUFFER_SIZE));
		c = read (fd, str, BUFFER_SIZE);
		if (c == -1)
		{
			free (str);
			return (NULL);
		}
		end = ft_strchr(str, '\n');
		strfull = ft_strjoin_for_gnl(strfull, str, i);
		i++;
		xx[0] = xx[0] + c;
	}
	return (strfull);
}

char	*ft_end_of_get_next_line(char *end, char *statka, char *str)
{
	if (end && end[1])
	{
		statka = ft_strdup(&end[1]);
		end[1] = '\0';
	}
	free (str);
	return (statka);
}

char	*get_next_line_free_part(char *s1, char *s2)
{
	free(s1);
	if (s2 != NULL)
		free (s2);
	return (NULL);
}

char	*get_next_line_main_part(int fd, char *str, int xx, char *end)
{
	static char	*statka;
	char		*strfull;

	strfull = NULL;
	if (statka)
	{
		end = ft_strchr(statka, '\n');
		strfull = ft_strjoin_for_gnl(strfull, statka, 0);
		xx++;
	}
	str[BUFFER_SIZE] = 0;
	if (!end)
		strfull = get_next_line_second_part(&xx, str, strfull, fd);
	if (strfull == NULL)
		return (0);
	end = ft_strchr(strfull, '\n');
	free(statka);
	statka = 0;
	if (!xx)
		return (get_next_line_free_part(str, strfull));
	statka = ft_end_of_get_next_line(end, statka, str);
	str = ft_strdup(strfull);
	free(strfull);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*str;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	str = malloc(BUFFER_SIZE + 1);
	if (!str)
		return (0);
	ft_bzero (str, (BUFFER_SIZE + 1));
	str = get_next_line_main_part(fd, str, 0, 0);
	return (str);
}
