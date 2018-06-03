/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_btreedelone.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vischlum <vischlum@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 15:37:00 by vischlum     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/15 10:58:00 by vischlum    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_btreedelone(t_btree **abtree, void (*del)(void *, size_t))
{
	if (!abtree && !del)
		return ;
	if (*abtree)
	{
		del((*abtree)->content, (*abtree)->content_size);
		free(*abtree);
		*abtree = NULL;
	}
}
