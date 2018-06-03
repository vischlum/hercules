/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sort_quicksort.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vischlum <vischlum@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 15:35:18 by vischlum     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/15 10:58:00 by vischlum    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../inc/libft.h"

static int	ft_partition(int *tab, int lo, int hi)
{
	int i;
	int j;
	int pivot;
	int swap;

	i = lo;
	j = hi;
	pivot = tab[lo];
	while (1)
	{
		while (tab[i] < pivot)
			i++;
		while (tab[j] > pivot)
			j--;
		if (i < j)
		{
			swap = tab[i];
			tab[i] = tab[j];
			tab[j] = swap;
		}
		else
			return (j);
	}
}

void		ft_sort_quicksort(int *tab, int lo, int hi)
{
	int p;

	if (lo < hi)
	{
		p = ft_partition(tab, lo, hi);
		ft_sort_quicksort(tab, lo, p);
		ft_sort_quicksort(tab, p + 1, hi);
	}
}
