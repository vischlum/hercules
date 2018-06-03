/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vischlum <vischlum@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 15:41:58 by vischlum     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/15 10:58:00 by vischlum    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../inc/libft.h"

static int		ft_nb_len(int n, int base)
{
	unsigned int	copy;
	int				len;

	copy = ABS(n);
	len = 0;
	while (copy != 0)
	{
		copy = copy / base;
		len++;
	}
	if (n < 0 && base == 10)
		len++;
	return (len);
}

char			*ft_itoa_base(int n, int base)
{
	int				len;
	int				i;
	unsigned int	copy;
	char			*output;
	char			*char_base;

	char_base = "0123456789ABCDEF";
	len = ft_nb_len(n, base);
	if ((output = malloc((sizeof(char) * (len + 1)))) == NULL)
		return (NULL);
	if (n == 0)
		return (output = "0\0");
	i = 0;
	copy = ABS(n);
	while (i++ < len)
	{
		output[len - i] = char_base[copy % base];
		copy = copy / base;
	}
	if (n < 0 && base == 10)
		output[0] = '-';
	output[len] = '\0';
	return (output);
}
