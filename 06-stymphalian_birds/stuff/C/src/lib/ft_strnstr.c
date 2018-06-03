/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vischlum <vischlum@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 15:35:55 by vischlum     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/15 10:58:00 by vischlum    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	char	*first;
	char	*target;
	size_t	i;

	if (!*to_find)
		return ((void *)str);
	while (len-- && *str)
	{
		if (*str == *to_find)
		{
			i = len;
			first = (void *)str + 1;
			target = (void *)to_find + 1;
			while (i-- && *first && *target && *first == *target)
			{
				first++;
				target++;
			}
			if (!*target)
				return ((void *)str);
		}
		str++;
	}
	return (NULL);
}
