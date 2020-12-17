/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apenrose <apenrose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 00:44:14 by apenrose          #+#    #+#             */
/*   Updated: 2020/12/16 19:48:48 by apenrose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		n_chr(const char *s, int c)
{	
	int i;
	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return (i + 1);
	return (0);
}

char    *part_two(char **line, char *ostatok)
{
    int     i_n;
    char    *after_n;
    char    *tmp;

    if (!(ostatok))
        return (0);
    else
    {
        i_n = n_chr(ostatok, '\n');
        tmp = ostatok;
        after_n = ft_substr(ostatok, i_n, ft_strlen(ostatok) - i_n);
        ostatok[i_n - 1] = '\0';
        *line = ft_strjoin(*line, ostatok);
        free (tmp);
        return (after_n);
    }


}

char    *part_one(char **line, char *buffer, char *ostatok, int i_rd)
{
//    int     i_n;
//    int     i_rd;
//    char	buffer[BUFFER_SIZE + 1];
//    char    *tmp;

    if (i_rd < 0)
        {
            free (ostatok);
            free(*line);
            ostatok = NULL;
            return (NULL);
        }
        buffer[i_rd] = '\0';
        //tmp = ostatok;
        ostatok = ft_strjoin(ostatok, buffer);
        //free(tmp);
//        free(buffer);
    return (ostatok);
}

int		get_next_line(int fd, char **line)
{
	static char *ostatok = NULL;
    char		buffer[BUFFER_SIZE + 1];
	int			i_rd = 0;
	int			i_n = 0;
	char 		*tmp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
        return (-1);
	*line = NULL;
    while (!(i_n = n_chr(ostatok, '\n')) && (i_rd = read(fd, buffer, BUFFER_SIZE)))
    {
        tmp = ostatok;
        ostatok = part_one(line, buffer, ostatok, i_rd);
        free (tmp);
        if (ostatok == NULL)
            return (-1);
    }

    i_n = n_chr(ostatok, '\n');
    //tmp = ostatok;
	ostatok = part_two(line, ostatok);
	//free (tmp);

	return (((i_rd == 0) && (i_n == 0)) ? 0 : 1);
}