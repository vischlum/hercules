/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vischlum <vischlum@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 15:35:46 by vischlum     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/15 10:58:00 by vischlum    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*ft_strstr(char *str, char *to_find)
{
	char	*first;
	char	*target;

	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		first = str;
		target = to_find;
		while (*str && *target && *str == *target)
		{
			str++;
			target++;
		}
		if (!*target)
			return (first);
		str = first + 1;
	}
	return (0);
}
