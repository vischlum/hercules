/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sort_insertion.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vischlum <vischlum@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 15:35:10 by vischlum     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/15 10:58:00 by vischlum    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_sort_insertion(int *tab, int size)
{
	int i;
	int j;
	int x;

	i = 1;
	while (i < size)
	{
		x = tab[i];
		j = i - 1;
		while (j >= 0 && tab[j] > x)
		{
			tab[j + 1] = tab[j];
			j--;
		}
		tab[j + 1] = x;
		i++;
	}
}
