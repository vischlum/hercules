/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strequ.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vischlum <vischlum@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 15:40:49 by vischlum     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/15 10:58:00 by vischlum    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	char	*ptr_s1;
	char	*ptr_s2;

	if (s1 && s2)
	{
		ptr_s1 = (char *)s1;
		ptr_s2 = (char *)s2;
		while (*ptr_s1 || *ptr_s2)
		{
			if (*ptr_s1 != *ptr_s2)
				return (0);
			ptr_s1++;
			ptr_s2++;
		}
		return (1);
	}
	return (0);
}
