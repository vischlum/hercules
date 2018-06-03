/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strndup.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vischlum <vischlum@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 14:48:11 by vischlum     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/15 10:58:00 by vischlum    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../inc/libft.h"

char	*ft_strndup(const char *src, size_t n)
{
	unsigned int	len;
	char			*output;

	len = ft_strlen(src);
	if (!(output = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	len = 0;
	while (src[len] != '\0' && len < n)
	{
		output[len] = src[len];
		len++;
	}
	output[len] = '\0';
	return (output);
}
