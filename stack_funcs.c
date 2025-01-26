/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakherra <aakherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 10:20:43 by aakherra          #+#    #+#             */
/*   Updated: 2025/01/14 23:06:23 by aakherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **h)
{
	t_list	*tmp;

	if (ft_lstsize(*h) > 1)
	{
		tmp = *h;
		*h = (*h)->next;
		tmp->next = (*h)->next;
		(*h)->next = tmp;
		(*h)->index = 0;
		(*h)->next->index = 1;
	}
}

void	push(t_list **s1, t_list **s2)
{
	t_list	*tmp;

	tmp = *s1;
	*s1 = (*s1)->next;
	tmp->next = *s2;
	*s2 = tmp;
	increment_idx((*s2)->next);
	decrement_idx(*s1);
}

void	rotate(t_list **h)
{
	t_list	*tmp;
	t_list	*last;

	if (ft_lstsize(*h) > 1)
	{
		tmp = (*h)->next;
		last = ft_lstlast(*h);
		last->next = *h;
		(*h)->next = NULL;
		(*h)->index = last->index + 1;
		*h = tmp;
		decrement_idx(*h);
	}
}

void	rev_rotate(t_list **h)
{
	t_list	*bef_last;
	t_list	*last;

	if (ft_lstsize(*h) > 1)
	{
		bef_last = ft_lstbefore_last(*h);
		last = bef_last->next;
		bef_last->next = NULL;
		last->next = *h;
		*h = last;
		(*h)->index = 0;
		increment_idx((*h)->next);
	}
}

void	init_target(t_list *h)
{
	while (h)
	{
		h->target = NULL;
		h = h->next;
	}
}
