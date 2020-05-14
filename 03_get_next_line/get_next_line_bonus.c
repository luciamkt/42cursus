/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltakahas <ltakahas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 11:09:28 by ltakahas          #+#    #+#             */
/*   Updated: 2020/05/14 14:28:15 by ltakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	ft_free(char **str)
{
	if (*str && str)
	{
		free(*str);
		*str = NULL;
	}
}

static int	ft_line_end(char **line, char **str, char *buf)
{
	char	*tmp;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(*str);
	if ((*str)[i] == '\n')
	{
		*line = ft_strdup("");
		tmp = ft_substr(*str, 1, len);
		ft_free(str);
		*str = tmp;
	}
	else
	{
		while ((*str)[i] && (*str)[i] != '\n')
			i++;
		*line = ft_substr(*str, 0, i);
		tmp = ft_substr(*str, i + 1, len - i);
		ft_free(str);
		*str = tmp;
	}
	ft_free(&buf);
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char	*str[OPEN_MAX];
	char		*buf;
	int			ret;

	buf = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf || fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);
	if (str[fd] == NULL)
		str[fd] = ft_strdup("");
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		str[fd] = ft_strjoin_free(str[fd], buf);
		if (ft_strchr(str[fd], '\n'))
			return (ft_line_end(line, &str[fd], buf));
	}
	if (ft_strchr(str[fd], '\n'))
		return (ft_line_end(line, &str[fd], buf));
	ft_line_end(line, &str[fd], buf);
	ft_free(&str[fd]);
	return (0);
}
