/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:32:45 by araymond          #+#    #+#             */
/*   Updated: 2023/01/18 15:53:29 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*t_new;

	t_new = (t_list *)malloc(sizeof(*t_new));
	if (!t_new)
		return (NULL);
	t_new->content = content;
	t_new->next = NULL;
	return (t_new);
}
