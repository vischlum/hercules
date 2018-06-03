/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vischlum <vischlum@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 11:21:21 by vischlum     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/15 10:58:00 by vischlum    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../inc/libft.h"

/*
** If the fd passed as argument is already in the list, return this node.
** Otherwise, create a new node and return it.
*/

static t_list	*get_fd(t_list **line, int fd)
{
	t_list	*temp;

	temp = *line;
	while (temp)
	{
		if ((int)temp->content_size == fd)
			return (temp);
		temp = temp->next;
	}
	temp = (t_list*)malloc(sizeof(t_list));
	temp->content_size = fd;
	temp->content = "";
	temp->next = (*line);
	(*line) = temp;
	return (temp);
}

/*
** Read the line passed as argument, and put it in line->content
** Return the return value of read
*/

static long		read_line(t_list *line)
{
	char	buff[BUFF_SIZE + 1];
	long	ret;
	char	*temp;

	ft_bzero(&buff, BUFF_SIZE + 1);
	ret = 1;
	while (ret > 0 && ft_strchr(line->content, '\n') == NULL)
	{
		ret = read((int)line->content_size, &buff, BUFF_SIZE);
		temp = ft_strjoin(line->content, buff);
		if (ft_strcmp(line->content, ""))
		{
			free(line->content);
			line->content = NULL;
		}
		line->content = temp;
		ft_bzero(&buff, BUFF_SIZE + 1);
	}
	return (ret);
}

/*
** Copy the string up until the first occurence of the char c
*/

static char		*strchrcpy(char *str, char c)
{
	char	*out;
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	out = ft_strnew(i);
	ft_strncpy(out, str, i);
	return (out);
}

/*
** If there is a '\n' in str, then return str without the '\n'
** Else return an empty string
*/

static char		*cleaner(char *str)
{
	char	*out;
	int		i;

	out = NULL;
	i = 0;
	if (ft_strchr(str, '\n') != NULL)
	{
		while (str[i] != '\n')
			i++;
		out = ft_strsub(str, i + 1, ft_strlen(str) - i);
	}
	else
		out = ft_strnew(0);
	ft_strdel(&str);
	return (out);
}

/*
** Everything is done through linked lists :
** - get_fd will return the link containing the appropriate fd
** - read_line will return the return value of read for the current line
*/

int				get_next_line(const int fd, char **line)
{
	static t_list	*fd_list = NULL;
	t_list			*current_fd;
	long			ret;

	if ((fd < 0 || BUFF_SIZE < 1 || !line || read(fd, &line, 0) < 0))
		return (-1);
	current_fd = get_fd(&fd_list, fd);
	ret = read_line(current_fd);
	*line = strchrcpy(current_fd->content, '\n');
	current_fd->content = cleaner(current_fd->content);
	if (ret == 0 && !**line)
		return (0);
	return (1);
}
