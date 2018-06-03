/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vischlum <vischlum@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 15:42:34 by vischlum     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/15 10:58:00 by vischlum    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../inc/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char		*dest_cpy;
	const char	*src_cpy;

	dest_cpy = dest;
	src_cpy = src;
	if (dest_cpy <= src_cpy || src_cpy >= (dest_cpy + len))
		while (len--)
			*dest_cpy++ = *src_cpy++;
	else
	{
		src_cpy = src_cpy + len - 1;
		dest_cpy = dest_cpy + len - 1;
		while (len--)
			*dest_cpy-- = *src_cpy--;
	}
	return (dest);
}
