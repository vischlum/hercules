/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vischlum <vischlum@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 15:42:56 by vischlum     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/15 10:58:00 by vischlum    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../inc/libft.h"

static int		ft_nb_len(int n)
{
	unsigned int	copy;
	int				len;

	copy = ABS(n);
	len = 0;
	while (copy != 0)
	{
		copy = copy / 10;
		len++;
	}
	if (n < 0)
		len++;
	return (len);
}

char			*ft_itoa(int n)
{
	int				len;
	int				i;
	unsigned int	copy;
	char			*output;

	len = ft_nb_len(n);
	if ((output = malloc((sizeof(char) * (len + 1)))) == NULL)
		return (NULL);
	if (n == 0)
	{
		output[0] = '0';
		output[1] = '\0';
		return (output);
	}
	i = 0;
	copy = ABS(n);
	while (i++ < len)
	{
		output[len - i] = (copy % 10) + '0';
		copy = copy / 10;
	}
	if (n < 0)
		output[0] = '-';
	output[len] = '\0';
	return (output);
}
