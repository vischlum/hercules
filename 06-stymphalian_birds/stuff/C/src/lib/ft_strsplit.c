/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vischlum <vischlum@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 15:35:29 by vischlum     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/15 10:58:00 by vischlum    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../inc/libft.h"

static int		cnt_spaceblk(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			if (s[i + 1] != c)
				count++;
		i++;
	}
	return (count + 2);
}

static int		count_char(char const *s, char c, size_t i)
{
	size_t count;

	count = 0;
	while (s[i])
	{
		if (s[i + 1] != c)
			count++;
		else
			break ;
		i++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**out;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	if (!s || !c || !(out = (char**)malloc(sizeof(char*) * cnt_spaceblk(s, c))))
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			k = 0;
			if (!(out[j] = malloc(sizeof(char) * (count_char(s, c, i) + 1))))
				return (NULL);
			while (s[i] != c && s[i] != '\0')
				out[j][k++] = s[i++];
			out[j++][k] = '\0';
		}
	}
	out[j] = NULL;
	return (out);
}
