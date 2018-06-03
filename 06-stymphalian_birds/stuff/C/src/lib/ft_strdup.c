/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vischlum <vischlum@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 15:40:37 by vischlum     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/15 10:58:00 by vischlum    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../inc/libft.h"

char	*ft_strdup(const char *src)
{
	int		len;
	char	*output;

	len = ft_strlen(src);
	if (!(output = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	len = 0;
	while (src[len] != '\0')
	{
		output[len] = src[len];
		len++;
	}
	output[len] = '\0';
	return (output);
}
