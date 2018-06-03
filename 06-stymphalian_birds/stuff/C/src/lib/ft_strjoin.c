/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vischlum <vischlum@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 15:38:26 by vischlum     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/15 10:58:00 by vischlum    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../inc/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*output;
	unsigned int	len;
	unsigned int	i;
	unsigned int	j;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(output = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j] != '\0')
		output[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		output[i++] = s2[j++];
	output[i] = '\0';
	return (output);
}
