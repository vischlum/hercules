/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_btreenew.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vischlum <vischlum@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 15:37:14 by vischlum     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/15 10:57:56 by vischlum    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../inc/libft.h"

t_btree	*ft_btreenew(void const *content, size_t content_size)
{
	t_btree *new;

	if (!(new = (t_btree*)malloc(sizeof(t_btree))))
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		if (!(new->content = malloc(content_size)))
			return (NULL);
		ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
	}
	new->left = NULL;
	new->right = NULL;
	return (new);
}
