/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vischlum <vischlum@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 15:35:36 by vischlum     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/15 10:58:00 by vischlum    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strtrim(char const *s)
{
	char	*output;
	char	*check_last;

	if (!s)
		return (NULL);
	while (*s && (*s == ' ' || *s == '\n' || *s == '\t'))
		s++;
	if (!(output = ft_strdup(s)))
		return (NULL);
	check_last = output + ft_strlen(output) - 1;
	while (check_last > output && (*check_last == ' ' || *check_last == '\n' ||
				*check_last == '\t'))
		*check_last-- = '\0';
	return (output);
}
