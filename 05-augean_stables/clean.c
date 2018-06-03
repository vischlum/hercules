/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   clean.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vischlum <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 10:25:21 by vischlum     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/07 10:53:33 by vischlum    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

long	sum_array(int *array, int size)
{
	long	sum;
	int		index;

	sum = 0;
	index = 0;
	while (index < size)
	{
		sum += array[index];
		index++;
	}
	return (sum);
}

void	allocate_loads_of_memory(void)
{
	int		*p1;
	char	*p2;
	int		*p3;
	int		index;

	index = 0;
	p1 = (int*)malloc(sizeof(int) * 4242);
	p2 = (char*)malloc(sizeof(char*) * 42);
	p3 = (int*)malloc(sizeof(int) * 424242);
	if (!p1 || !p2 || !p3)
		return ;
	bzero(p1, sizeof(int) * 4242);
	bzero(p2, sizeof(int) * 42);
	bzero(p3, sizeof(int) * 424242);
	memset(p2, 42, 42);
	memset(p1, 42, 4242);
	while (index++ < 424242)
		p3[index] = index * 42;
	printf("%ld\n%s\n%ld\n", sum_array(p1, 4242), p2, sum_array(p3, 424242));
	free(p1);
	p1 = NULL;
	free(p2);
	p2 = NULL;
	free(p3);
	p3 = NULL;
}

int		main(void)
{
	allocate_loads_of_memory();
	return (0);
}
